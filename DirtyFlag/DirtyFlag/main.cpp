// 脏标记模式：
//	一组原始数据随时间变化。一组衍生数据经过一些代价昂贵的操作由这些数据确定。一个脏标记跟踪这个衍生数据是否和原始数据同步。
//	它在袁术数据改变时被设置。如果它被设置了，那么当需要衍生数据时，他们就会被重新计算并且标记被清除。否则就使用缓存的数据。

// 使用情境:
//	就像大多数优化那样，仅当性能问题严重到值得增加代码复杂度时才使用它。

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
