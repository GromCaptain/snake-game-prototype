#include "QtWindowImpl.h"

#include <QPainter>

#include "Graph/PlatformSpecific/Qt/QtTextureImpl.h"

WindowImpl::WindowImpl(QWidget *parent) : QWidget(parent)
	{
	connect(this, SIGNAL(displayableImageChanged()), this, SLOT(update()), Qt::QueuedConnection);
	}

void WindowImpl::setWindowType(WindowType type)
	{
	//
	}

void WindowImpl::setResolution(unsigned W, unsigned H)
	{
	resize(W, H);
	}

void WindowImpl::renderTexture(const Graphics::TextureImpl& texture)
	{
	displayableImage = texture.image();
	emit displayableImageChanged();
	}

void WindowImpl::paintEvent(QPaintEvent*)
	{
	QPainter painter(this);
	painter.drawImage(rect(), displayableImage);
	}
