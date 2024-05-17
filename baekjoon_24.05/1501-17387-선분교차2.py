x1, y1, x2, y2 = map(int, input().split())
x3, y3, x4, y4 = map(int, input().split())


def ccw(x1, y1, x2, y2, x3, y3):
    return (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1)


a = ccw(x1, y1, x2, y2, x3, y3)
b = ccw(x1, y1, x2, y2, x4, y4)
c = ccw(x3, y3, x4, y4, x1, y1)
d = ccw(x3, y3, x4, y4, x2, y2)


if a * b == 0 and c * d == 0:
    x1, x2 = min(x1, x2), max(x1, x2)
    x3, x4 = min(x3, x4), max(x3, x4)
    y1, y2 = min(y1, y2), max(y1, y2)
    y3, y4 = min(y3, y4), max(y3, y4)
    if x1 <= x4 and x2 >= x3 and y1 <= y4 and y2 >= y3:
        print(1)
    else:
        print(0)
else:
    if a * b <= 0 and c * d <= 0:
        print(1)
    else:
        print(0)


# def lefttoright(x1, y1, x2, y2):
#     if x1 > x2:
#         return (x2, y2, x1, y1)
#     else:
#         return (x1, y1, x2, y2)


# def getequation(x1, y1, x2, y2):
#     xdiff = x2 - x1
#     ydiff = y2 - y1
#     if xdiff == 0:
#         return (0, x1)
#     a = ydiff / xdiff
#     b = y1 - a * x1
#     return (1, a, b)


# def figure_two_vertical(y1, y2, y3, y4):
#     if y1 > y3:
#         y1, y2, y3, y4 = y3, y4, y1, y2
#     return y2 >= y3


# def figure_one_vertical(xval, eq2, p1, p2):
#     _, a, b = eq2
#     y = a * xval + b
#     x1, y1, x2, y2 = p1
#     x3, y3, x4, y4 = p2
#     if (y1 < y and y2 < y) or (y1 > y and y2 > y):
#         return 0
#     if (y3 < y and y4 < y) or (y3 > y and y4 > y):
#         return 0
#     return 1


# def figure_none_vertical(eq1, eq2, p1, p2):
#     _, a1, b1 = eq1
#     _, a2, b2 = eq2
#     x1, y1, x2, y2 = p1
#     x3, y3, x4, y4 = p2

#     if a2 == a1:
#         if b1 != b2:
#             return 0

#         if y1 > y3:
#             y1, y2, y3, y4 = y3, y4, y1, y2
#         if y2 >= y3:
#             return 1
#         else:
#             return 0

#     xval = (b2 - b1) / (a1 - a2)

#     # print(xval)
#     if (x1 < xval and x2 < xval) or (x1 > xval and x2 > xval):
#         return 0
#     if (x3 < xval and x4 < xval) or (x3 > xval and x4 > xval):
#         return 0
#     return 1


# def testcase(x1, y1, x2, y2, x3, y3, x4, y4):
#     x1, y1, x2, y2 = lefttoright(x1, y1, x2, y2)
#     x3, y3, x4, y4 = lefttoright(x3, y3, x4, y4)
#     if (x1, y1) in ((x3, y3), (x4, y4)) or (x2, y2) in ((x3, y3), (x4, y4)):
#         return 1
#     eq1 = getequation(x1, y1, x2, y2)
#     eq2 = getequation(x3, y3, x4, y4)
#     # print(eq1)
#     # print(eq2)
#     if eq1[0] == 0 and eq2[0] == 0:
#         if eq1[1] == eq2[1]:
#             return figure_two_vertical()
#         else:
#             return 0
#     p1 = (x1, y1, x2, y2)
#     p2 = (x3, y3, x4, y4)
#     if eq1[0] == 0 and eq2[0] == 1:
#         return figure_one_vertical(eq1[1], eq2, p1, p2)
#     if eq2[0] == 0 and eq1[0] == 1:
#         return figure_one_vertical(eq2[1], eq1, p2, p1)
#     if eq1[0] == 1 and eq2[0] == 1:
#         return figure_none_vertical(eq1, eq2, p1, p2)


# print(int(testcase(x1, y1, x2, y2, x3, y3, x4, y4)))
