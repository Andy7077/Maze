#include "cgt215.h"
#include "demo.h"
#include <time.h>

using namespace cgt215;

//Character variables
int x = 26;    
int y = 11;
int t = 1; 

void initializeArrayGrid(int gridArr[26][51]) {
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 51; j++) {
			gridArr[i][j] = 0;
		}
	}
	for (int i = 2; i < 49; i++) {
		gridArr[2][i] = 1;
	}
	for (int i = 2; i < 24; i++) {
		gridArr[i][2] = 1;
	}
	for (int i = 2; i < 49; i++) {
		gridArr[23][i] = 1;
	}
	for (int i = 3; i < 21; i++) {
		gridArr[i][48] = 1;
	}
	for (int i = 5; i < 18; i++) {
		gridArr[5][i] = 1;
	}
	for (int i = 6; i < 18; i++) {
		gridArr[i][11] = 1;
	}
	for (int i = 6; i < 21; i++) {
		gridArr[i][5] = 1;
	}
	for (int i = 8; i < 21; i++) {
		gridArr[i][8] = 1;
	}
	for (int i = 9; i < 18; i++) {
		gridArr[20][i] = 1;
	}
	for (int i = 11; i < 21; i++) {
		gridArr[17][i] = 1;
	}
	for (int i = 8; i < 17; i++) {
		gridArr[i][17] = 1;
	}
	for (int i = 8; i < 17; i++) {
		gridArr[i][14] = 1;
	}
	for (int i = 21; i < 46; i++) {
		gridArr[5][i] = 1;
	}
	for (int i = 5; i < 21; i++) {
		gridArr[i][20] = 1;
	}
	for (int i = 21; i < 49; i++) {
		gridArr[20][i] = 1;
	}
	for (int i = 24; i < 49; i++) {
		gridArr[17][i] = 1;
	}
	for (int i = 8; i < 18; i++) {
		gridArr[i][23] = 1;
	}
	for (int i = 24; i < 43; i++) {
		gridArr[8][i] = 1;
	}
	for (int i = 30; i < 43; i++) {
		gridArr[11][i] = 1;
	}
	for (int i = 5; i < 12; i++) {
		gridArr[i][45] = 1;
	}
	for (int i = 24; i < 46; i++) {
		gridArr[14][i] = 1;
	}
	gridArr[21][17] = 1;
	gridArr[22][17] = 1;
	gridArr[9][30] = 1;
	gridArr[10][30] = 1;
}

//Used to help me visualize the maze when building the array
	//void printArrayGrid(int gridArr[26][51]) {
	//	for (int i = 0; i < 26; i++) {
	//		for (int j = 0; j < 51; j++) {
	//			std::cout << gridArr[i][j] << " ";
	//		}
	//		std::cout << std::endl;
	//	}
	//}

void DrawMaze() {
    setColor(0, 1, 1);

	int gridArr[26][51];

	initializeArrayGrid(gridArr);

	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 51; j++) {
			if (gridArr[i][j] == 1) {
				drawRectangle(j * 25, i * 25, 25, 25);
			}
		}
	}
}

void DrawChara() {
    setColor(1, 1, 0);
	
	drawRectangle(x * 25, y * 25, 25, 25);

	int gridArr[26][51];

	initializeArrayGrid(gridArr);
	
    if (keyPressed('w')) {
		if (gridArr[y][x] == 0) {
			y = y + t;
			if (gridArr[y][x] != 0) {
				y = y - t;
			}
		}

	};

  if (keyPressed('a')) {
	  if (gridArr[y][x] == 0) {
		  x = x - t;
		  if (gridArr[y][x] != 0) {
			  x = x + t;
		  }
	  }
  };

  if (keyPressed('s')) {
	  if (gridArr[y][x] == 0) {
		  y = y - t;
		  if (gridArr[y][x] != 0) {
			  y = y + t;
		  }
	  }
};
  if (keyPressed('d')) {
	  if (gridArr[y][x] == 0) {
		  x = x + t;
		  if (gridArr[y][x] != 0) {
			  x = x - t;
		  }
	  }
  };
}

void renderFrame(float lastFrameDuration) {

    setWireframeRendering(false);
   
    DrawMaze();

    DrawChara();
}


void cgtConsole() {

}

int main(int argc, char** argv) {
    srand((unsigned int)time(NULL));

	int gridArr[26][51];
	
	initializeArrayGrid(gridArr);
	
	//printArrayGrid(gridArr);

	enable3d();

    initializeCgt215(argc, argv, cgtConsole, renderFrame, "CGT 215");
}
