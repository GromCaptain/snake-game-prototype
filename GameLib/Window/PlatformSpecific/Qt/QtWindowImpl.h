#ifndef WINDOW_IMPL_H
#define WINDOW_IMPL_H

#include <QWidget>

#include <QImage>

#include "Input/Input.h"
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

	Input::Input& input();

	protected:
	void paintEvent(QPaintEvent*) override;

	void keyPressEvent(QKeyEvent* event) override;
	void keyReleaseEvent(QKeyEvent* event) override;
	void mousePressEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;

	signals:
	void displayableImageChanged();

	public slots:

	private:
	QImage displayableImage;
	Input::Input input_;
	};

}

#endif // WINDOW_IMPL_H
