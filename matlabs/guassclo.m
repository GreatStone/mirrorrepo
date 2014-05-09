function [X] = guassclo (A,b)
	[n,n] = size(A);
	for i = 1:n-1
		[clomax,index]=max(abs(A(i:n,i)));
		index = index + i - 1;
		if (clomax < 1e-6)
			fprintf('The main element is too small\n');
			return;
		end

		if (index ~= i)
			tmp = A(i,1:n);
			A(i,1:n) = A(index,1:n);
			A(index,1:n) = tmp;
			tmp = b(i,1);
			b(i,1) = b(index,1);
			b(index,1) = tmp;
		end

		for j = i+1:n
			tmp = A(i,i) / A(j,i);
			A(j,i:n) = A(j,i:n) * tmp - A(i,i:n);
			b(j,1) = b(j,1) * tmp - b(i,1);
		end
	end

	X=zeros(n,1);
	for i = n:-1:1
		tmp = A(i,i+1:n) * X(i+1:n,1);
		s = b(i,1) - tmp;
		X(i,1) = s / A(i,i);
	end
end