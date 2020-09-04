%Hough Transform for Circle Detection
img = imread('circles1.jpg');
try
    img = rgb2gray(img);
catch
    disp('already a gray image');
end
figure,
edgemap = edge(img,'canny');
imshow(edgemap); title('Edge Map');

Px = [-1 0 1; -1 0 1; -1 0 1];
Py = [1 1 1; 0 0 0; -1 -1 -1];

Ix = filter2(Px,edgemap);
Iy = filter2(Py,edgemap);

figure,
imshow(Ix); title('Edge IX');
figure,
imshow(Iy); title('Edge IY');

rows = size(img,1);
columns = size(img,2);

Array = zeros(rows, columns, 150);
[Imag,Idir] = imgradient(edgemap);

for x = 1:rows-1
    for y = 1:columns-1
        if(edgemap(x,y)>0)
            angle=Idir(x,y);
            for r = 1:150
                Xc = round(x+r*cos(angle));
                Yc = round(y+r*sin(angle));
                if(1<=Xc && Xc<=rows && 1<=Yc && Yc<=columns)
                    Array(Xc,Yc,r) = Array(Xc,Yc,r)+1;
                end
            end
        end
    end
end

[MaxValue,Index] = max(Array(:));
[row, col, radius]=ind2sub(size(Array),Index);
