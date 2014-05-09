function [X] =  Jacobi(A,b)
	Bj = A;
	[n,n] = size(A);
	b2 = b;
	for i = 1:n
		for j = 1:n
			if (i == j)
				Bj(i,j) = 0;
			else
				Bj(i,j) = -A(i,j)/A(i,i);
			end
		end
		b2(i,1) = b(i,1) / A(i,i);
	end
	Xpre = zeros (n,1);
	X = Bj * Xpre + b2;
	while true
		if (len(X - Xpre) < 1e-4)
			break;
		else
			Xpre = X;
			X = Bj * Xpre + b2;
		end
	end
end