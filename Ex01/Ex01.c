#include <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS

enum POLYGON { QUADRILATERAL = 4, PENTAGON = 5 };
typedef enum POLYGON POLYGON;

typedef struct polygon {
	POLYGON type;
	// choose your representation for the vertices
} Polygon;

struct Node {
	struct polygon* poly;
	struct Node* next;
};

typedef struct Coordinate {
	char x;
	char y;
	char mander; //jk tzvi metargel
} Coordinate;

void add_polygon(struct polygon*); // add new polygon to the list
void print_polygon(struct polygon*); // print the type of polygon and its vertices
void print_perimeter(struct polygon*); // calculate and print the perimeter
void print_diagonals(struct polygon*); // calculate and print the length of all diagonals
void print_area(struct polygon*); // calculate and print the area


int main()
{
	long long int givenOrder = 0;
	long long int LastCommandMask = 1;
	long long int NewPolygonMask = 2;
	long long int PolygonTypeMask = 4;
	long long int OutputTypeMask = 120;
	long long int DestinationPolygonsMask = 384;
	long long int CoordinateExtractionMask = 0xFF;
	long long int quadCoords = 0;
	long long int pentaCoords1 = 0, pentaCoords2;
	Coordinate* coord;

	while (1)
	{
		printf("Enter Num\n");
		scanf("%x", &givenOrder);

		if ((givenOrder & NewPolygonMask) == NewPolygonMask)
		{
			long long int bla = givenOrder & PolygonTypeMask;
			if ((givenOrder & PolygonTypeMask) == 0)
			{
				scanf("%llx", &quadCoords);
				coord = (Coordinate*)malloc(4 * sizeof(Coordinate));
				for (int i = 0; i < QUADRILATERAL; i++)
				{
					coord[i].x = quadCoords & CoordinateExtractionMask;
					quadCoords = quadCoords >> 8;
					coord[i].y = quadCoords & CoordinateExtractionMask;
					quadCoords = quadCoords >> 8;
				}
			}
			else if ((givenOrder & PolygonTypeMask) != 0)
			{
				scanf("%llx", &pentaCoords1);
				scanf("%llx", &pentaCoords2);
				
				coord = (Coordinate*)malloc(5 * sizeof(Coordinate));
				for (int i = 0; i < QUADRILATERAL; i++)
				{
					coord[i].x = pentaCoords1 & CoordinateExtractionMask;
					pentaCoords1 = pentaCoords1 >> 8;
					coord[i].y = pentaCoords1 & CoordinateExtractionMask;
					pentaCoords1 = pentaCoords1 >> 8;
				}
				coord[4].x =pentaCoords2 & CoordinateExtractionMask;
				pentaCoords2 = pentaCoords2 >> 8;
				coord[4].y = pentaCoords2 & CoordinateExtractionMask;

			}
			else
			{
				printf("Invalid Shape Type Input\n");
				break;
			}


			//Polygon* newPolygon = (Polygon*)malloc(sizeof(Polygon));

			//add_polygon(newPolygon);
		}




		if (givenOrder & LastCommandMask == LastCommandMask)
		{
			printf("Goodbye my lover, good bye my friend\nYou have been the one for me\n J.Blunt");
			break;
		}
	}

	system("pause");
	return 0;
}
