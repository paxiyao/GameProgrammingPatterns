// ����ģʽ��
//	һ��ԭʼ������ʱ��仯��һ���������ݾ���һЩ���۰���Ĳ�������Щ����ȷ����һ�����Ǹ���������������Ƿ��ԭʼ����ͬ����
//	����Ԭ�����ݸı�ʱ�����á�������������ˣ���ô����Ҫ��������ʱ�����Ǿͻᱻ���¼��㲢�ұ�Ǳ�����������ʹ�û�������ݡ�

// ʹ���龳:
//	���������Ż����������������������ص�ֵ�����Ӵ��븴�Ӷ�ʱ��ʹ������

#define MAX_CHILDREN 20

class Mesh
{
};

class Transform
{
public:
	static Transform origin();
	Transform combine(Transform& other);
};

class GraphNode
{
public:
	GraphNode(Mesh* mesh)
		:_mesh(mesh),
		 _local(Transform::origin()),
		 _dirty(true)
	{ }

	void render(Transform parentWorld, bool dirty)
	{
		dirty |= _dirty;
		if (dirty)
		{
			_world = _local.combine(parentWorld);
			_dirty = false;
		}

		if (_mesh) renderMesh(_mesh, _world);

		for (int i = 0; i < _numChildren; i++)
		{
			_children[i]->render(_world, dirty);
		}
	}

	void renderMesh(Mesh* mesh, Transform transform)
	{

	}
private:
	Transform _local;
	Transform _world;
	Mesh* _mesh;
	bool _dirty;

	GraphNode* _children[MAX_CHILDREN];
	int _numChildren;
};

int main()
{
	return 0;
}
