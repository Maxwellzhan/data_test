
def add_complex_and_rational(c, r):
    """Return c + r for complex c and rational r."""
    return ComplexRI(c.real + r.numer/r.denom, c.imag)

def mul_complex_and_rational(c, r):
    """Return c * r for complex c and rational r."""
    r_magnitude, r_angle = r.numer/r.denom, 0
    if r_magnitude < 0:
        r_magnitude, r_angle = -r_magnitude, pi
    return ComplexMA(c.magnitude * r_magnitude, c.angle + r_angle)

def add_rational_and_complex(r, c):
    return add_complex_and_rational(c, r)

def mul_rational_and_complex(r, c):
    return mul_complex_and_rational(c, r)

class Number:
	def __add__(self, other):
		if self.typeflag == other.typeflag:
			return self.add(other)
		elif (self.typeflag, other.typeflag) in self.adders:
			return self.cross_apply(other, self.adders)

	def __mul__(self, other):
		if self.typeflag == other.typeflag:
			return self.mul(other)
		elif (self.typeflag, other.typeflag) in self.multipliers:
			return self.cross_apply(other, self.multipliers)

	def cross_apply(self, other, cross_fns):
		cross_fn = cross_fns[(self.typeflag, other.typeflag)]
		return cross_fn(self, other)

	adders = {('com', 'rat'):add_complex_and_rational,
			  ('rat', 'com'):add_rational_and_complex}

	multipliers = {('com', 'rat'):mul_complex_and_rational,
				   ('rat', 'com'):mul_rational_and_complex}	

class Ration(Number):
	typeflag = 'rat'
	def __init__(self, numer, denom):
		self.numer = numer
		self.denom = denom

	def __repr__(self):
		return 'Ration({0}, {1})'.format(self.numer, self.denom)

	def __str__(self):
		return '{0}/{1}'.format(self.numer, self.denom)

	@property
	def float_value(self):
		return self.numer/self.denom

class Complex(Number):
	typeflag = 'com'
	def add(self, other):
		return ComplexRI(self.real + other.real, 
						 self.imag + other.imag)

	def mul(self, other):
		return ComplexMA(self.magnitude * other.magnitude,
						 self.angle + other.angle)

class ComplexRI(Complex):
	def __init__(self, real, imag):
		self.real = real
		self.imag = imag

	@property
	def magnitude(self):
		return (self.real ** 2 + self.imag ** 2)**0.5

	@property
	def angle(self):
		return atan2(self.real, self.imag)

	def __repr__(self):
		return 'ComplexRI({0}, {1})'.format(self.real, self.imag)

class ComplexMA(Complex):
	def __init__(self, magnitude, angle):
		self.magnitude = magnitude
		self.angle = angle

	@property
	def real(self):
		return self.magnitude * cos(self.angle)

	@property
	def imag(self):
		return self.magnitude * sin(self.angle)

	def __repr__(self):
		return 'ComplexMA({0:g}, {1:g})'.format(self.magnitude, self.angle)	


def f(n, mul):
	if n == 0:
		return mul;
	else:
		return f(n-1, mul*n)

def ff(n):
	if n == 0:
		return 1
	else:
		return n*ff(n-1)