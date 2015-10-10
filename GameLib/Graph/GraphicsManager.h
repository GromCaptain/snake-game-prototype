#ifndef GRAPHICS_MANAGER_H
#define GRAPHICS_MANAGER_H


class GraphicsManager
	{
	public:
	static GraphicsManager& instance();

	void init();

	private:
	GraphicsManager();
	};

#endif // GRAPHICS_MANAGER_H
