def tree(plist,l,a,f):
	"""plist:pen list
   	 l :pen size
   	 a :half of angle
   	 f :pen size shorten factor"""
	if l>5:
		lst=[]
		for p in plist:
			p.forward(l)
			q=p.clone()
			p.left(a)
			q.right(a)
			lst.append(p)
			lst.append(q)
		tree(lst,l*f,a,f)
