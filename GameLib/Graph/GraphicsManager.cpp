#include "GraphicsManager.h"

GraphicsManager::GraphicsManager()
	{
	}

GraphicsManager& GraphicsManager::instance()
	{
	static GraphicsManager mgr;
	return mgr;
	}

void GraphicsManager::init()
	{
	//
	}
