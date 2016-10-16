#include <QApplication>

#include "GameEngine/States/GameManager.h"

int main(int argc, char *argv[])
	{
	QApplication a(argc, argv);

	GameEngine::GameManager::instance().start();

	return a.exec();
	}
