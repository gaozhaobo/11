function [ X ] = AXXB( A,B )
%一串神秘代码，解决手眼标定
%AXXB 使用了K积方法，计算手眼标定问题中的AX=XB问题
    n=size(A,3)
    K=[];
    I=eye(3,3);
    for i=2:n
        RA=A(1:3,1:3,i);
        RB=B(1:3,1:3,i);
        K=[K;kron(I,RA)-kron(RB',I)];
    end
    [U,S,V]=svd(K);
    col=length(V);
    RX=-[V(1:3,col),V(4:6,col),V(7:9,col)];

    [Ux,Sx,Vx]=svd(RX);
    RX=Ux*Vx';
    RX=sign(det(RX))*RX;
    [ Error,err,average_err ] = AXXB_Error( A(1:3,1:3,:),B(1:3,1:3,:),RX );
    
    At=[];
    bt=[];
    for i=2:n
        RA=A(1:3,1:3,i);
        tB=B(1:3,4,i);
        tA=A(1:3,4,i);
        At=[At;I-RA];
        bt=[bt;tA-RX*tB];
    end
    tx=At\bt;
    X=[RX,tx;0,0,0,1];
    [ Error,err,average_err ] = AXXB_Error( A,B,X );
end

