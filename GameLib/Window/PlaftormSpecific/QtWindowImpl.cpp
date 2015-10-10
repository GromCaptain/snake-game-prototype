#include "QtWindowImpl.h"

WindowImpl::WindowImpl(QWidget *parent) : QWidget(parent)
	{
	}

//WindowImpl::WindowImpl(const WindowImpl& wnd):
//	QWidget(wnd)
//	{
//	}

void WindowImpl::setWindowType(WindowType type)
	{
	//
	}

void WindowImpl::setResolution(unsigned W, unsigned H)
	{
	resize(W, H);
	}

