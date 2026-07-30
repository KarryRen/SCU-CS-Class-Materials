n = 0:35;
x1d = sin(pi*n/4) .* cos(pi*n/4);
x2d = cos(pi*n/4) .* cos(pi*n/4);
x3d = sin(pi*n/4) .* cos(pi*n/8);

t = 0:0.01:35;
x1c = sin(pi*t/4) .* cos(pi*t/4);
x2c = cos(pi*t/4) .* cos(pi*t/4);
x3c = sin(pi*t/4) .* cos(pi*t/8);

figure;
subplot(3, 1, 1);
stem(n, x1d);
hold on;
plot(t, x1c);
xlabel('n');
ylabel('x_1[n]');
subplot(3, 1, 2);
stem(n, x2d);
hold on;
plot(t, x2c);
xlabel('n');
ylabel('x_2[n]');
subplot(3, 1, 3);
stem(n, x3d);
hold on;
plot(t, x3c);
xlabel('n');
ylabel('x_3[n]');