#include <QtWebKit>

class WebkitVideoCapture;
class CutyPage : public QWebPage {
  Q_OBJECT

public:
  void setAttribute(QWebSettings::WebAttribute option, const QString& value);
  void setUserAgent(const QString& userAgent);
  void setAlertString(const QString& alertString);
  void setPrintAlerts(bool printAlerts);
  void setWebkitVideoCapture(WebkitVideoCapture* capt);
  QString getAlertString();

protected:
  QString chooseFile(QWebFrame *frame, const QString& suggestedFile);
  void javaScriptConsoleMessage(const QString& message, int lineNumber, const QString& sourceID);
  bool javaScriptPrompt(QWebFrame* frame, const QString& msg, const QString& defaultValue, QString* result);
  void javaScriptAlert(QWebFrame* frame, const QString& msg);
  bool javaScriptConfirm(QWebFrame* frame, const QString& msg);
  QString userAgentForUrl(const QUrl& url) const;
  QString mUserAgent;
  QString mAlertString;
  bool mPrintAlerts;
  WebkitVideoCapture* mWebkitVideoCapture;
};

class WebkitVideoCapture : public QObject {
  Q_OBJECT

public:

  // TODO: This should really be elsewhere and be named differently
  enum OutputFormat { SvgFormat, PdfFormat, PsFormat, InnerTextFormat, HtmlFormat,
    RenderTreeFormat, PngFormat, JpegFormat, MngFormat, TiffFormat, GifFormat,
    BmpFormat, PpmFormat, XbmFormat, XpmFormat, OtherFormat };

  WebkitVideoCapture(CutyPage* page,
           const QString& output,
           int delay,
		   		 int length,
					 int fps,
           OutputFormat format,
           const QString& scriptProp,
           const QString& scriptCode);

private slots:
  void DocumentComplete(bool ok);
  void InitialLayoutCompleted();
  void JavaScriptWindowObjectCleared();
  void Timeout();
  void Delayed();
  void saveSnapshot();

private:
  void TryDelayedRender();
  bool mSawInitialLayout;
  bool mSawDocumentComplete;
	void captureFinished();

protected:
  QString      mOutput;
  int          mDelay;
	int 				 mLength;
	int					 mFps;
  CutyPage*    mPage;
  OutputFormat mFormat;
  QObject*     mScriptObj;
  QString      mScriptProp;
  QString      mScriptCode;

	int 				mCurrentFrame;
	int					mMaxFrame;
	QTimer			timer;
};
