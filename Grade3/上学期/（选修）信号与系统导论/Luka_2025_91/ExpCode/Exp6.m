t = 0:0.002:1;
fc = 3;
x_org = cos(2*pi*fc*t);

fs = 10;
T = 1/fs;
nT = 0:T:1;
n = length(nT);
x_sp = zeros(1,n);
for i=1:n
    x_sp(i) = cos(2*pi*fc*nT(i));
end
m = length(t);
x_re = zeros(1,m);
for i = 1:m
    for j = 1:n
        % x_re(i) = x_re(i)+x_sp(j)*sin(pi*(t(i)-nT(j))/T)/(pi*(t(i)-nT(j))/T);
        x_re(i) = x_re(i)+x_sp(j)*sinc((t(i)-nT(j))/T);
    end
end

plot(t,x_org,t,x_re,'linewidth',1.5);grid on