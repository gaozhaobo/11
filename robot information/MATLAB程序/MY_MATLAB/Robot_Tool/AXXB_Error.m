function [ Error,err,average_err ] = AXXB_Error( A,B,X )
%AXXB_Error 用于简单得到标定的误差
    n=length(A);
    sz=size(A);
    Error=zeros(sz(1),sz(1),n);
    err=zeros(n,1);
    average_err=0;
    Y1=zeros(sz(1),sz(1),n);
    Y2=zeros(sz(1),sz(1),n);
    for i=1:n
        Y1(:,:,i)=A(:,:,i)*X;
        Y2(:,:,i)=X*B(:,:,i);
        Error(:,:,i)=Y1(:,:,i)-Y2(:,:,i);
        err(i)=norm(Error(:,:,i));
        average_err=average_err+err(i);
    end
    average_err=average_err/length(err);
end
