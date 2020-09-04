%%%%% Haris Corner Detection %%%%%
img = imread('chess.jpg');
try
    img = rgb2gray(img);
catch
    disp('already a gray image');
end

% Derivatives of Gaussian Gx and Gy
G1= fspecial('gaussian',[7 7],2);
[Gx,Gy] = gradient(G1);

%%%%% STEP NO 01 %%%%%
% Compute Ix and Iy using derivatives of gaussian
Ix = filter2(Gx,img);
Iy = filter2(Gy,img);
%____________________%
%%%%% STEP NO 02 %%%%%
% Form 3 matrices : Ix2 , Iy2 and IxIy
Ix2 = Ix.^2;
Iy2 = Iy.^2;
IxIy = Ix.*Iy;
%____________________%
%%%%% STEP NO 03 %%%%%
% Convolve the above 3 matrices with a larger gaussian
lg = fspecial('gaussian',[25 25],3);
Ix2 = filter2(lg,Ix2);
Iy2 = filter2(lg,Iy2);
IxIy = filter2(lg,IxIy);
%____________________%
rows = size(img,1);
columns = size(img,2);
R = zeros(rows,columns);
corners = zeros(rows,columns);

%%%%% STEP NO 04 %%%%%
% Compute a scalar value R at each pixel of image
for i = 1:rows
    for j = 1:columns
        A = [Ix2(i,j) IxIy(i,j); IxIy(i,j) Iy2(i,j)];
        R(i,j) = det(A)-0.06*(trace(A))^2;
    end
end
%____________________%
%%%%% STEP NO 05 %%%%%
% Threshold R and use non-maxima suppression
maxValue = max(max(R)); % finds maximum value in matrix R
for i = 2:rows-1
    for j = 2:columns-1
        % Threshold R
        if R(i,j) > (maxValue/40)
            % Non-maxima suppression
            if R(i,j)>R(i-1,j-1) && R(i,j)>R(i-1,j) && R(i,j)>R(i-1,j+1) && R(i,j)>R(i,j-1) && R(i,j)>R(i,j+1) && R(i,j)>R(i+1,j-1) && R(i,j)>R(i+1,j) && R(i,j)>R(i+1,j+1)
                corners(i,j) = 1;
            end
        end
    end
end
%____________________%
%%%%% Displaying Results %%%%%
[colNo, rowNo] = find(corners == 1);
figure,
imshow(img); title('Image');
figure,
imshow(corners); title('Corners');
figure,
imshow(img); title('Detected Corners');
hold on;
plot(rowNo,colNo,'g*');
plot(rowNo,colNo,'yO');
hold off