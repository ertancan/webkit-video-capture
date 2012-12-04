webkit-video-capture
====================

An extension to CutyCapt project(http://cutycapt.sourceforge.net/) that captures multiple frames from given url.
Currently does not generate a video output but you may feed the resulting images into ffmpeg (ffmpeg -i yourfile-%5d.png output.avi) (if you are using png and you want avi and you don't need to change the frame rate of course)

Added Options:

length: length of video (in seconds)
fps:	frame rate of video

Other options should work without a problem but i didn't check them yet.