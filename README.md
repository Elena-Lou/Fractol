# Fractol

Fractol is a computer graphics project to render two sets of fractals : Mandelbrot and Julia.

## Compilation

To compile the project, including my Libft and 42's own graphics library, the MinilibX
```bash
make all
```

To launch a window displaying Mandelbrot set
```c
./fractol Mandelbrot
```
![Mandelbrot](/images/Red_Mandelbrot.png)

Different sets of Julia can be displayed depending on the parameters provided. Here are two examples :

```c
./fractol Julia -0.8 0.156
```
![Julia](/images/Red_Julia.png)

```c
./fractol 0.285 0.01
```
![Julia](/images/Red_Julia_bis.png)

More examples can be found [on wikipedia](https://en.wikipedia.org/wiki/Julia_set)