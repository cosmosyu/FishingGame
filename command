g++ -c Scene.cpp -I../sfml2_1/include
g++ Scene.o -o run_app -L../sfml2_1/lib -lGLEW -lsfml-graphics -lsfml-window -lsfml-system
export LD_LIBRARY_PATH=../sfml2_1/lib
