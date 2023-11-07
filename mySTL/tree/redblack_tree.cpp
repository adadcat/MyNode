//实现一个红黑树

namespace miniSTL
{
	//定义节点颜色
	typedef bool rb_tree_color_type;
	typedef rb_tree_color_type color_type;
	const bool rb_tree_red = true;
	const bool rb_tree_black = false;

	//定义树
	struct rb_tree_base
	{
		typedef rb_tree_base* pBase;

		color_type color;//节点颜色
		pBase parent;//父节点
		pBase left;//左节点
		pBase right;//右节点

		//最小节点（树最左节点）
		static pBase get_min_node(pBase x)
		{
			while (x->left != nullptr)
			{
				x = x->left;
			}
			return x;
		}

		//最大节点（树最右节点）
		static pBase get_max_node(pBase x)
		{
			while (x->right != nullptr)
			{
				x = x->right;
			}
			return x;
		}

		//获取兄弟节点
		pBase get_brother_node()
		{
			if (this->parent->left == this)
			{
				return this->parent->right;
			}
			return this->parent->left;
		}
	};

	//存储节点值
	template<class Value>
	struct rb_tree_node : public rb_tree_base
	{
		typedef rb_tree_node<Value>* node_pointer;
		Value value_field;	//节点值
	};

	//迭代器
	struct rb_tree_iterator_base
	{
		typedef rb_tree_base::pBase base_ptr;
		//
		//

		base_ptr node;

		rb_tree_iterator_base(base_ptr n) :node(n) {}

		//operator++
		void increment()
		{
			//如果没有右节点
			if (node->right == node)
			{
				return;
			}

			if (node->right != nullptr)
			{
				//如果node有右节点，就找该右节点的最左节点
				node = node->right;

				while (node->left != nullptr)
				{
					node = node->left;
				}
			}
			else
			{
				//node没有右节点
				//找到节点的父节点。如果该父节点，本身是右节点，就往上追溯，直到不为右节点
				base_ptr parent = node->parent;
				
				while (parent->right == node)
				{
					node = parent;
					parent = node->parent;
				}


				//若此时的右子节点不等于父节点
				//则父节点即为解答，否则此时的node为解答
				//这里判断“若此时的右子节点不等于父节点”是为了应付一种特殊情况：我们求right-most
				//结点的下一节点。以上特殊做法必须配合RB-tree根节点与header之间的特殊关系
				if (node->right != parent) 
				{		
					node = parent;					
				}
			}
		}

		//operator--
		void decrement()
		{
			if (node->left == node)
			{
				return;
			}

			if (node->color == rb_tree_red && node->parent->parent == node)
			{
				//如果node是红，且父节点的父节点指向自己
				//则此时的node指向header(即end())。相当于执行 --end()，right-most 即为解答
				//注意：header之右子节点即right-most，执行整棵树的max节点
				node = node->right;
			}
			else if (node->left != nullptr) 
			{	//如果有左子节点
				node = node->left;				//令 node 指向其左子节点
				while (node->right != nullptr)	//找到左子节点的最右节点即为解答
				{
					node = node->right;
				}
			}
			else 
			{	
				//node既header节点也无左子节点
				//找到 node 的父节点
				base_ptr parent = node->parent;	

				while (node == parent->left) 
				{			
					//当现行节点身为左子节点
					//一直往上走，直至不为左子节点
					node = parent;						
					parent = node->parent;
				}
				//此时的父节点即为解答
				node = parent;			
			}
		}
	};

	template<class Value,class Ref,class Ptr>
	struct rb_tree_iterator : public rb_tree_iterator_base
	{
		typedef Value value_type;

	};
}