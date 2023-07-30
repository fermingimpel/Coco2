cd %1\res
mkdir Shaders
copy "%2\Coco2\Shaders\fragment.shader" "%1\res\Shaders" /Y
copy "%2\Coco2\Shaders\vertex.shader" "%1\res\Shaders" /Y
cd %1\Bin\Debug
mkdir res
cd %1\Bin\Debug\res
mkdir Shaders
copy "%2\Coco2\Shaders\fragment.shader" "%1\Bin\Debug\res\Shaders" /Y
copy "%2\Coco2\Shaders\vertex.shader" "%1\Bin\Debug\res\Shaders" /Y