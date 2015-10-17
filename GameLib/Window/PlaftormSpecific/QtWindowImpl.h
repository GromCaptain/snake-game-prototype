#ifndef WINDOW_IMPL_H
#define WINDOW_IMPL_H

#include <QWidget>

#include "Window/WindowType.h"

class WindowImpl : public QWidget
	{
	Q_OBJECT
	public:
	explicit WindowImpl(QWidget *parent = 0);

	void setWindowType(WindowType type);
	void setResolution(unsigned W, unsigned H);

	signals:

	public slots:
	};

#endif // WINDOW_IMPL_H
