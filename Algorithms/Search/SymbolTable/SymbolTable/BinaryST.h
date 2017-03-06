// -------
// 二叉查找树
// 2017.03.06
// -------
#ifndef BINARY_ST_H
#define BINARY_ST_H

#include <cstddef>
using namespace std;

template<typename Key, typename Value>
class BinaryST
{
private:
	class Node;
	typedef int Size;
	class Node
	{
	public:
		Key key;
		Value val;
		Node *left, *right;
		Size N;
		Node(Key& key, Value& val, Size N) : key(key), val(val), N(N)
		{
			cout << &key << " - " << &this->key << endl;
		}
	};

private:
	Node *root;

public:
	BinaryST() :root(nullptr){}
	// 表中的键值对数量
	Size size(){ return size(root); }

	// 传入Key的值，获取key对应的值，若key不存在则返回NULL
	Value get(const Key& key){ return get(root, key); }
	// 传入Key的指针，获取key对应的值，若key不存在则返回NULL
	Value get(const Key* key){ return get(root, *key); }
	// 将键值对存入表中，若值为空则将键key从表中删除；若key存在，则复写key对应的值
	void put(Key& key, Value& val){ root = put(root, key, val);	}
	void put(Key* key, Value& val){ root = put(root, *key, val); }

	// 最小的键
	Key min(){ return min(root)->key; }
	// 最大的键
	Key max(){ return max(root)->key; }
	
	// 小于等于key的最大值
	Key floor(Key& key)
	{
		Node *x = floor(root, key);
		if (nullptr == x) return NULL;
		return x->key;
	}
	// 大于等于key的最小值
	Key ceiling(Key& key)
	{
		Node *x = ceiling(root, key);
		if (nullptr == x) return NULL;
		return x->key;
	}

	// 排名为k的键
	Key select(int k){ return select(root, k)->key; }
	// 小于key的键的数量
	int rank(Key& key){ return rank(key, root); }

	// 删除最小的键
	void deleteMin();
	// 删除最大的键
	void deleteMax();

	// [lo..hi]之间键的数量
	Size size(Key& lo, Key& hi);

private:
	Size size(Node *x)
	{
		return nullptr == x ? 0 : x->N;
	}
	Value get(Node *x, const Key& key)
	{
		if (nullptr == x) return NULL;
		if (key < x->key) return get(x->left, key);
		else if (key > x->key) return get(x->right, key);
		else return x->val;
	}
	Node *put(Node *x, Key& key, Value& val)
	{
		if (nullptr == x) return new Node(key, val, 1);

		if (key < x->key) x->left = put(x->left, key, val);
		else if (key > x->key) x->right = put(x->right, key, val);
		else x->val = val;
		x->N = size(x->left) + size(x->right) + 1;
		return x;
	}	
	Node *min(Node *x)
	{
		if (nullptr == x->left) return x;
		return min(x->left);
	}
	Node *max(Node *x)
	{
		if (nullptr == x->right) return x;
		return max(x->right);
	}
	Node *floor(Node *x, Key& key)
	{
		if (nullptr == x) return nullptr;
		if (key == x->key) return x;
		if (key < x->key) return floor(x->left, key);

		Node *t = floor(x->right, key);
		return nullptr != t ? t : x;
	}
	Node *ceiling(Node *x, Key& key)
	{
		if (nullptr == x) return nullptr;
		if (key == x->key) return x;
		if (key > x->key) return floor(x->right, key);

		Node *t = ceiling(x->left, key);
		return nullptr != t ? t : x;
	}
	Node *select(Node *x, int k)
	{
		if (nullptr == x) return nullptr;
		int t = size(x.left);
		if (t > k) return select(x->left, k);
		else if (t < k) return select(x->right, k - t - 1);
		else return x;
	}
	int rank(Key key, Node *x)
	{
		if (nullptr == x) return nullptr;
		if (key < x->key) return rank(key, x->left);
		else if (key > x->key) return 1 + size(x->left) + rank(key, x->right);
		else return size(x->left);
	}
};

#endif // ! BINARY_ST_H