function [res] = len(A)
	[n,m] = size(A);
	res = 0;
	for i = 1:n
		res = res + A(i,1) * A(i,1);
	end
	res = sqrt(res);
end