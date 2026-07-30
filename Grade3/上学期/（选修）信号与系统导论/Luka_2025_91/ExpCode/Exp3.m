n1 = 0:5;
h = n1;
n2 = 0:7;
x = ones(1, 8);

figure;
subplot(2, 2, 1);
stem(n1, h);
xlabel('n');
ylabel('h[n]');

subplot(2, 2, 2);
stem(n2, x);
xlabel('n');
ylabel('x[n]');

n3 = 0:12;
y = conv(x, h);
subplot(2, 1, 2);
stem(n3, y);
xlabel('n');
ylabel('y[n]');
