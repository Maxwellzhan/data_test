def main():
 #打开文件
 f1=open('TeleAddressBook.txt','rb')
 f2=open('EmailAddressBook.txt','rb')
 
 #跳过第一行
 f1.readline()
 f2.readline()
 
 #读整段文件
 lines1=f1.readlines()
 lines2=f2.readlines()
 
 #变量存储
 list1_name=[]
 list1_tele=[]
 list2_name=[]
 list2_email=[]
 
 #信息存储
 for line in lines1:
  element=line.split()
  list1_name.append(str(element[0].decode('gbk')))
  list1_tele.append(str(element[1].decode('gbk')))

 for line in lines2:
  element=line.split()
  list2_name.append(str(element[0].decode('gbk')))
  list2_name.append(str(element[1].decode('gbk')))

 #合并处理
 lines=[]
 lines.append('姓名\t			电话\t			邮箱')

 for i in range(len(list1_name)):
  s=''
  if list1_name[i] in list2_name:
    j=list2_name.index(list1_name[i])
    s='\t'.join([list1_name[i], list1_tele[i], list2_email[j]])
    s+='\n'
  else:
    s='\t'.join([list1_name[i],list1_tele[i],str('_________')])
    s+='\n'
  lines.append(s)
 
 for i in range(len(list2_name)):
  s=''
  if list2_name[i] not in list1_name:
    s='\t'.join([list2_name[i],str('_________'),list2_email[i]])
    s+='\n'
  lines.append(s)

 #写入并关闭文件
 f3=open('zonghe.txt','w')
 f3.writelines(lines)
 f1.close()
 f2.close()
 f3.close()

main()	
