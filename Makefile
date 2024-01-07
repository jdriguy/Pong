output: main.o Game.o Menu.o Theme.o Paddle.o PlayerPaddle.o EnemyPaddle.o Score.o Ball.o
	g++ main.o Game.o Menu.o Theme.o Paddle.o PlayerPaddle.o EnemyPaddle.o Ball.o Score.o -o output -Linclib/lib -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

main.o: src/main.cpp
	g++ -Iinclib/include/ -c src/main.cpp

Game.o: src/Game.cpp
	g++ -Iinclib/include/ -c src/Game.cpp

Menu.o: src/Menu.cpp
	g++ -Iinclib/include/ -c src/Menu.cpp

Theme.o: src/Theme.cpp
	g++ -Iinclib/include/ -c src/Theme.cpp

Paddle.o: src/Paddle.cpp
	g++ -Iinclib/include/ -c src/Paddle.cpp

PlayerPaddle.o: src/PlayerPaddle.cpp
	g++ -Iinclib/include/ -c src/PlayerPaddle.cpp

EnemyPaddle.o: src/EnemyPaddle.cpp
	g++ -Iinclib/include/ -c src/EnemyPaddle.cpp

Score.o: src/Score.cpp
	g++ -Iinclib/include/ -c src/Score.cpp

Ball.o: src/Ball.cpp
	g++ -Iinclib/include/ -c src/Ball.cpp

clean:
	del /s *.o output.exe