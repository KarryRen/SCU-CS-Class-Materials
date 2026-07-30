n = -5000:5000;
T = 1 / 10000;
t = n * T;
x = sin(pi*1000*t);

N1 = 10;
T1 = N1 * T;
t1 = t(1:N1:end);
x1 = x(1:N1:end);

N2 = 13;
T2 = N2 * T;
t2 = t(1:N2:end);
x2 = x(1:N2:end);

subplot(3, 1, 1);
plot(2/T*t, abs(fftshift(fft(x)))); grid on;
subplot(3, 1, 2);
plot(2/T1*t1, abs(fftshift(fft(x1)))); grid on;
subplot(3, 1, 3);
plot(2/T2*t2, abs(fftshift(fft(x2)))); grid on;
