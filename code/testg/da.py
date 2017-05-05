import turtle

def main():
	
	#窗口
	turtle.title("动态绘制")
	turtle.setup(800,600,0,0)
	
	#画笔
	pen=turtle.Turtle()
	pen.color("red")
	pen.width(5)
	pen.shape("turtle")
	pen.speed(1)
	
	#读文件
	result=[]
	file=open("data.txt","r")
	for line in file:
		#result.append(list(map(float, line.split(','))))
		result.append(list(map(float, line.split(','))))
	print(result)
	for i in range(len(result)):
		pen.color(result[i][3],result[i][4],result[i][5])
		pen.forward(result[i][0])
		if result[i][1]:
			pen.rt(result[i][2])
		else:
			pen.lt(result[i][2])
		pen.goto(0,0)
	
if __name__ == '__main__':
	main()
					
