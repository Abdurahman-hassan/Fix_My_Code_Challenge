#!/usr/bin/python3
"""This module creates a class square"""


class Square():
    """This class creates a square object"""
    width = 0
    height = 0

    def __init__(self, *args, **kwargs):
        """Initializes the square object"""
        for key, value in kwargs.items():
            setattr(self, key, value)

    def area_of_my_square(self):
        """Calculates the area of the square"""
        """ Area of the square """
        return self.width * self.width

    def permiter_of_my_square(self):
        """Calculates the perimeter of the square"""
        return (self.width * 2) + (self.height * 2)

    def __str__(self):
        """Returns the string representation of the square object"""
        return "{}/{}".format(self.width, self.height)


if __name__ == "__main__":
    """This is executed when the module is run as a script"""
    s = Square(width=12, height=9)
    print(s)
    print(s.area_of_my_square())
    print(s.permiter_of_my_square())
