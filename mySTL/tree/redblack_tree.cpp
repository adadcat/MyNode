//ʵ��һ�������

namespace miniSTL
{
	//����ڵ���ɫ
	typedef bool rb_tree_color_type;
	typedef rb_tree_color_type color_type;
	const bool rb_tree_red = true;
	const bool rb_tree_black = false;

	//������
	struct rb_tree_base
	{
		typedef rb_tree_base* pBase;

		color_type color;//�ڵ���ɫ
		pBase parent;//���ڵ�
		pBase left;//��ڵ�
		pBase right;//�ҽڵ�

		//��С�ڵ㣨������ڵ㣩
		static pBase get_min_node(pBase x)
		{
			while (x->left != nullptr)
			{
				x = x->left;
			}
			return x;
		}

		//���ڵ㣨�����ҽڵ㣩
		static pBase get_max_node(pBase x)
		{
			while (x->right != nullptr)
			{
				x = x->right;
			}
			return x;
		}

		//��ȡ�ֵܽڵ�
		pBase get_brother_node()
		{
			if (this->parent->left == this)
			{
				return this->parent->right;
			}
			return this->parent->left;
		}
	};

	//�洢�ڵ�ֵ
	template<class Value>
	struct rb_tree_node : public rb_tree_base
	{
		typedef rb_tree_node<Value>* node_pointer;
		Value value_field;	//�ڵ�ֵ
	};

	//������
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
			//���û���ҽڵ�
			if (node->right == node)
			{
				return;
			}

			if (node->right != nullptr)
			{
				//���node���ҽڵ㣬���Ҹ��ҽڵ������ڵ�
				node = node->right;

				while (node->left != nullptr)
				{
					node = node->left;
				}
			}
			else
			{
				//nodeû���ҽڵ�
				//�ҵ��ڵ�ĸ��ڵ㡣����ø��ڵ㣬�������ҽڵ㣬������׷�ݣ�ֱ����Ϊ�ҽڵ�
				base_ptr parent = node->parent;
				
				while (parent->right == node)
				{
					node = parent;
					parent = node->parent;
				}


				//����ʱ�����ӽڵ㲻���ڸ��ڵ�
				//�򸸽ڵ㼴Ϊ��𣬷����ʱ��nodeΪ���
				//�����жϡ�����ʱ�����ӽڵ㲻���ڸ��ڵ㡱��Ϊ��Ӧ��һ�����������������right-most
				//������һ�ڵ㡣�������������������RB-tree���ڵ���header֮��������ϵ
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
				//���node�Ǻ죬�Ҹ��ڵ�ĸ��ڵ�ָ���Լ�
				//���ʱ��nodeָ��header(��end())���൱��ִ�� --end()��right-most ��Ϊ���
				//ע�⣺header֮���ӽڵ㼴right-most��ִ����������max�ڵ�
				node = node->right;
			}
			else if (node->left != nullptr) 
			{	//��������ӽڵ�
				node = node->left;				//�� node ָ�������ӽڵ�
				while (node->right != nullptr)	//�ҵ����ӽڵ�����ҽڵ㼴Ϊ���
				{
					node = node->right;
				}
			}
			else 
			{	
				//node��header�ڵ�Ҳ�����ӽڵ�
				//�ҵ� node �ĸ��ڵ�
				base_ptr parent = node->parent;	

				while (node == parent->left) 
				{			
					//�����нڵ���Ϊ���ӽڵ�
					//һֱ�����ߣ�ֱ����Ϊ���ӽڵ�
					node = parent;						
					parent = node->parent;
				}
				//��ʱ�ĸ��ڵ㼴Ϊ���
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