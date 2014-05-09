function [X] = guass(A,b)
	[n,n]=size(A);
	for i = 1:n-1
		for j = i+1:n
			tmp = A(j,i) / A(i,i);
			A(j,i:n) = A(j,i:n) - A(i,i:n) * tmp;
			b(j,1) = b(j,1) - b(i,1) * tmp;
		end
	end
	X = zeros(n,1);
	for i = n:-1:1
		tmp = A(i,i+1:n) * X(i+1:n,1);
		s = b(i,1) - tmp;
		X(i,1) = s / A(i,i);
	end
end