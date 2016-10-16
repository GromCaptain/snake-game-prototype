#ifndef WINDOW_IMPL_H
#define WINDOW_IMPL_H

#include <QWidget>

#include <QImage>

#include "Window/WindowType.h"

namespace Graphics
{
class TextureImpl;
}

namespace Window
{

class WindowImpl : public QWidget
	{
	Q_OBJECT
	public:
	explicit WindowImpl(QWidget *parent = 0);

	void setWindowType(WindowType type);
	void setResolution(unsigned W, unsigned H);

	void renderTexture(const Graphics::TextureImpl& texture);

	void paintEvent(QPaintEvent*) override;

	signals:
	void displayableImageChanged();

	public slots:

	private:
	QImage displayableImage;
	};

}

#endif // WINDOW_IMPL_H
