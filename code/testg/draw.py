from turtle import Turtle
from tre import tree
def main():
	p=Turtle()
	p.pensize(5)
	p.hideturtle()
	p.color("green")
	p.speed(15)
	p.left(90)
	p.penup()
	p.goto(0,-200)
	p.pendown()
	t=tree([p],200,65,0.6375)
	input()

main()
