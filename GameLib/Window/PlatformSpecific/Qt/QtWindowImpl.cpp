#include "QtWindowImpl.h"

#include <QPainter>

#include "Graph/GraphCore/PlatformSpecific/Qt/QtTextureImpl.h"
#include "Input/PlatformSpecific/Qt/QtInputImpl.h"

namespace Window
{

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
	displayableImage_ = texture.image();
	emit displayableImageChanged();
	}

Input::Input& WindowImpl::input()
	{
	return input_;
	}

void WindowImpl::paintEvent(QPaintEvent*)
	{
	QPainter painter(this);
	painter.drawImage(rect(), displayableImage_);
	}

void WindowImpl::keyPressEvent(QKeyEvent* event)
	{
	input_.impl().registerKeyPressEvent(event);
	}

void WindowImpl::keyReleaseEvent(QKeyEvent* event)
	{
	input_.impl().registerKeyReleaseEvent(event);
	}

void WindowImpl::mousePressEvent(QMouseEvent* event)
	{
	input_.impl().registerMousePressEvent(event);
	}

void WindowImpl::mouseReleaseEvent(QMouseEvent* event)
	{
	input_.impl().registerMouseReleaseEvent(event);
	}

void WindowImpl::mouseMoveEvent(QMouseEvent* event)
	{
	input_.impl().registerMouseMoveEvent(event);
	}

}
