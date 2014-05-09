function [X] = gaussseidelit(A,b)
	[n,n] = size(A);
	Xpre = zeros(n,1);
	X = Xpre;
	e = 0;
	while true
		for i = 1:n
			X(i,1) = (b(i,1) - A(i,1:i-1) * X(1:i-1,1) - A(i,i+1:n) * Xpre(i+1:n,1))./A(i,i);
		end
		e = e+1;
		if (len(X - Xpre) < 1e-4)
			fprintf('%d\n', e);
			break;
		else
			Xpre = X;
		end
	end
end