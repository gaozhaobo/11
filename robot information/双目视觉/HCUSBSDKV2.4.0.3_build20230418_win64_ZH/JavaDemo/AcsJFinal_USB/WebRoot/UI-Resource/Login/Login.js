//登录设备
function LoginSubmit(){
	var dwVID=$("input#dwVID").val();
	var dwPID=$("input#dwPID").val();
	var szSerialNumber=$("input#szSerialNumber").val();
	var szUserName=$("input#szUserName").val();
	var password=$("input#password").val();
	
	var strJSON ={"dwVID":dwVID,"dwPID":dwPID,"szSerialNumber":szSerialNumber,"szUserName":szUserName,"password":password};
	jQuery.ajax({
		url:"hikvision/userCheck",
		type:"POST",
		data:strJSON,
		success:function(obj){
			if(obj.loginResult==1){
				alert("Login success!");
			}else{
				alert("Login failed111! Please check!");
			}
		},
		error:function(){
			alert("Login failed222 ! Please check!");
		},
		complete:function(obj){

		}
	});
}

//枚举设备
function EnumDevice(){
	jQuery.ajax({
		url:"hikvision/enumDevice",
		type:"GET",
		success:function(obj){
			if(obj.enumResult==1){				
				alert("enumDevice success, deviceInfo:"+obj.deviceInfo);
			}else if(obj.enumResult == 0){
				alert("no device was found! Please check!");
			}
			else{
				alert("enumDevice failed111 ! Please check!");
			}
		},
		error:function(){
			alert("enumDevice failed222 ! Please check!");
		},
		complete:function(obj){

		}
	});
}


//激活卡
function ActivateCard(){	
	jQuery.ajax({
		url:"hikvision/activateCard",
		type:"GET",		
		success:function(obj){
			if(obj.activeResult==1){				
				alert("ActivateCard success, card:"+obj.cardInfo);
			}
			else{
				alert("ActivateCard failed111 ! Please check!");
			}
		},
		error:function(){
			alert("ActivateCard failed222 ! Please check!");
		},
		complete:function(obj){

		}
	});
}


function GetCertificateInfo(){
	
    var player = document.getElementById('player');
    player.src="";
    
    var info = document.getElementById('szInfo');
    info.value = "";
	
	jQuery.ajax({
		url:"hikvision/getCertificateInfo",
		type:"GET",		
		success:function(obj){
			console.log(obj);
			if(obj.getCertificateInfoResult==1){	
			    player = document.getElementById('player');
			    player.src='data:image/jpeg;base64,'+obj.pictureData;
			    
			    info = document.getElementById('szInfo');
			    info.value = obj.certificateInfo;
			}
			else if(obj.getCertificateInfoResult==2){
				alert("GetCertificateInfo failed ! Please login first!");
			}
			else{
				alert("GetCertificateInfo failed ! Please check!");
			}
		},
		error:function(){
			alert("GetCertificateInfo failed ! Please check!");
		},
		complete:function(obj){

		}
	});
	
}