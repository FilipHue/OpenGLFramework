#pragma once

#include <iostream>

typedef struct colour Colour;
struct colour {
	float red;
	float green;
	float blue;

	colour(float red, float green, float blue) : red((float)red / 255), green((float)green / 255), blue((float)blue / 255) {}

	friend std::ostream& operator<<(std::ostream& os, const Colour& c) {
		os << "(" << c.red << ", " << c.green << ", " << c.blue << ")";

		return os;
	};
};

const Colour RED = Colour{ 255, 0, 0 };
const Colour GREEN = Colour{ 0, 255, 0 };
const Colour BLUE = Colour{ 0, 0, 255 };
const Colour WHITE = Colour{ 255, 255, 255 };
const Colour BLACK = Colour{ 0, 0, 0 };
const Colour GREY = Colour{ 128, 128, 128 };
