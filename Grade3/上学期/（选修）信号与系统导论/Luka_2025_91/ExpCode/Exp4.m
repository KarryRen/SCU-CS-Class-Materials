T = 4; %周期
t = -4:0.02:4; %信号的抽样点
N = 10; %谐波个数
a0 = 0.5;
X1 = a0 * ones(1, length(t));
for k = 1:2:N %偶次谐波为0
    X1 = X1 + cos(pi*k*t/2) * sinc(k/2);
end

figure;
plot(t, X1);
hold on;
plot(t, 0.5+0.5*square(2*pi*(t + 1)/T, 50))
title('N = 10')
axis([-4, 4, -0.2, 1.2]);
