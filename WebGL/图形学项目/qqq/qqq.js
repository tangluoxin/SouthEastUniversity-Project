"use strict";

var canvas;
var gl;
var program;

var modelViewMatrix, normalMatrix;
var modelViewMatrixLoc, normalMatrixLoc;

var lightPosition = vec4(0.8, 0.8, 0.8, 1.0 );
var lightAmbient = vec4(0.2, 0.2, 0.2, 1.0 );
var lightDiffuse = vec4( 1.0, 1.0, 1.0, 1.0 );
var lightSpecular = vec4( 1.0, 1.0, 1.0, 1.0 );

var materialAmbient = vec4( 1.0, 0.0, 1.0, 1.0 );
var materialDiffuse = vec4( 1.0, 0.8, 0.0, 1.0);
var materialSpecular = vec4( 1.0, 0.8, 0.0, 1.0 );
var materialShininess = 100.0;
var t;
// 小人1
var points1 = []; // 顶点容器
var normals1 = []; // 法向量容器
var texCoordsArray1 = [];//纹理坐标容器
var vNormal1, vPosition1, vTexCoord1;
var nBuffer1, vBuffer1, tBuffer1;
var CubeTx1 = 0, CubeTy1 = 0, CubeTz1 = 0;
var CubeRotateAngle1 = 0;
var scalePercent1 = 0.5; // 缩放比例
var direct1 = vec4( 0.0, 0.0, 1.0, 1.0 ); // 当前正面方向
//左手
var points_1 = []; // 顶点容器
var normals_1 = []; // 法向量容器
var texCoordsArray_1 = [];//纹理坐标容器
var vNormal_1, vPosition_1, vTexCoord_1;
var nBuffer_1, vBuffer_1, tBuffer_1;
var CubeRotateAngleX_1 = 0; 
var CubeRotateAngleZ_1 = 0;
var direct_1 = 0;//决定手臂前摆(0)还是后摆(1)
//右手
var points_2 = []; // 顶点容器
var normals_2 = []; // 法向量容器
var texCoordsArray_2 = [];//纹理坐标容器
var vNormal_2, vPosition_2, vTexCoord_2;
var nBuffer_2, vBuffer_2, tBuffer_2;
var CubeRotateAngleX_2 = 0;
var CubeRotateAngleZ_2 = 0;
var direct_2 = 0;
//左腿
var points_3 = []; // 顶点容器
var normals_3 = []; // 法向量容器
var texCoordsArray_3 = [];//纹理坐标容器
var vNormal_3, vPosition_3, vTexCoord_3;
var nBuffer_3, vBuffer_3, tBuffer_3;
var CubeRotateAngleX_3 = 0;
var CubeRotateAngleZ_3 = 0;
var direct_3 = 0;//决定手臂前摆(0)还是后摆(1)
//右腿
var points_4 = []; // 顶点容器
var normals_4 = []; // 法向量容器
var texCoordsArray_4 = [];//纹理坐标容器
var vNormal_4, vPosition_4, vTexCoord_4;
var nBuffer_4, vBuffer_4, tBuffer_4;
var CubeRotateAngleX_4 = 0;
var CubeRotateAngleZ_4 = 0;
var direct_4 = 0;//决定手臂前摆(0)还是后摆(1)

//小人2
var points2 = [];
var normals2 = [];
var texCoordsArray2 = [];//纹理坐标容器
var vNormal2, vPosition2, vTexCoord2;
var nBuffer2, vBuffer2, tBuffer2;
var CubeTx2 = 0, CubeTy2 = 0, CubeTz2 = 0;
var CubeRotateAngle2 = 0;
var scalePercent2 = 0.5; // 缩放比例
var direct2 = vec4( 0.0, 0.0, 1.0, 1.0 ); // 当前正面方向

//光源
var points3 = [];
var normals3 = [];
var texCoordsArray3 = [];//纹理坐标容器
var vNormal3, vPosition3, vTexCoord3;
var nBuffer3, vBuffer3, tBuffer3;
var CubeTx3 = lightPosition[0], CubeTy3 = lightPosition[1], CubeTz3 = lightPosition[2]; //光源平移量
var scalePercent3 = 1; // 缩放比例

//礼物盒
var points4 = [];
var normals4 = [];
var texCoordsArray4 = [];//纹理坐标容器
var vNormal4, vPosition4, vTexCoord4;
var nBuffer4, vBuffer4, tBuffer4;
var CubeTx4 = 0, CubeTy4 = 0, CubeTz4 = 0;
var CubeRotateAngle4 = 0;
var scalePercent4 = 0.5; // 缩放比例
var direct4 = vec4( 0.0, 0.0, 1.0, 1.0 ); // 当前正面方向

//地面
var points5 = [];
var normals5 = [];
var texCoordsArray5 = [];//纹理坐标容器
var vNormal5, vPosition5, vTexCoord5;
var nBuffer5, vBuffer5, tBuffer5; // 地面的buffer

var currentAngle = [0.0, 0.0]; // [绕x轴旋转角度，绕y轴旋转角度]

var viewMatrixLoc;
var viewMatrix;
var viewIndex = 0;

var near = 0.1;
var far = 10.0;

var  fovy = 60.0;  // Field-of-view in Y direction angle (in degrees)
var  aspect = 1;       // Viewport aspect ratio

var projectionMatrix;
var projectionMatrixLoc;

var a = 0;
var z=0.5;
var w=0.5;
var r=2;
var dr = 5.0 * Math.PI/180.0;

var texCoord = [
    vec2(0, 0),
    vec2(0, 1),
    vec2(1, 1),
    vec2(1, 0)
];

function configureTexture1(image) {
    var texture = gl.createTexture();
    gl.activeTexture(gl.TEXTURE1);

    gl.bindTexture(gl.TEXTURE_2D, texture);
    gl.pixelStorei(gl.UNPACK_FLIP_Y_WEBGL, true);
    gl.texImage2D(gl.TEXTURE_2D, 0, gl.RGB,
         gl.RGB, gl.UNSIGNED_BYTE, image);
    gl.generateMipmap(gl.TEXTURE_2D);
    gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MIN_FILTER, 
    	              gl.NEAREST_MIPMAP_LINEAR);
 
    gl.uniform1i(gl.getUniformLocation(program, "texture1"), 1);
}

function configureTexture2( image ) {
    var texture = gl.createTexture();
    gl.activeTexture(gl.TEXTURE2);

    gl.bindTexture( gl.TEXTURE_2D, texture );
    gl.pixelStorei(gl.UNPACK_FLIP_Y_WEBGL, true);
    gl.texImage2D( gl.TEXTURE_2D, 0, gl.RGB,
         gl.RGB, gl.UNSIGNED_BYTE, image );
    gl.generateMipmap( gl.TEXTURE_2D );
    gl.texParameteri( gl.TEXTURE_2D, gl.TEXTURE_MIN_FILTER, gl.NEAREST_MIPMAP_LINEAR );

    gl.uniform1i(gl.getUniformLocation(program, "texture2"), 2);
}

function configureTexture3( image ) {
    var texture = gl.createTexture();
    gl.activeTexture(gl.TEXTURE3);

    gl.bindTexture( gl.TEXTURE_2D, texture );
    gl.pixelStorei(gl.UNPACK_FLIP_Y_WEBGL, true);
    gl.texImage2D( gl.TEXTURE_2D, 0, gl.RGB,
         gl.RGB, gl.UNSIGNED_BYTE, image );
    gl.generateMipmap( gl.TEXTURE_2D );
    gl.texParameteri( gl.TEXTURE_2D, gl.TEXTURE_MIN_FILTER, gl.NEAREST_MIPMAP_LINEAR );

    gl.uniform1i(gl.getUniformLocation(program, "texture3"), 3);
}

function configureTexture4( image ) {
    var texture = gl.createTexture();
    gl.activeTexture(gl.TEXTURE4);

    gl.bindTexture( gl.TEXTURE_2D, texture );
    gl.pixelStorei(gl.UNPACK_FLIP_Y_WEBGL, true);
    gl.texImage2D( gl.TEXTURE_2D, 0, gl.RGB,
        gl.RGB, gl.UNSIGNED_BYTE, image );
    gl.generateMipmap( gl.TEXTURE_2D ); // 这句话会报错，就直接注释掉了
    gl.texParameteri( gl.TEXTURE_2D, gl.TEXTURE_MIN_FILTER,
        gl.NEAREST_MIPMAP_LINEAR );
    gl.texParameteri( gl.TEXTURE_2D, gl.TEXTURE_MAG_FILTER, gl.NEAREST );

    gl.uniform1i(gl.getUniformLocation(program, "texture4"), 4);
}

function configureTexture5( image ) {
    var texture = gl.createTexture();
    gl.activeTexture(gl.TEXTURE5);

    gl.bindTexture( gl.TEXTURE_2D, texture );
    gl.pixelStorei(gl.UNPACK_FLIP_Y_WEBGL, true);
    gl.texImage2D( gl.TEXTURE_2D, 0, gl.RGB,
         gl.RGB, gl.UNSIGNED_BYTE, image );
    gl.generateMipmap( gl.TEXTURE_2D );
    gl.texParameteri( gl.TEXTURE_2D, gl.TEXTURE_MIN_FILTER,
                      gl.NEAREST_MIPMAP_LINEAR );
    gl.texParameteri( gl.TEXTURE_2D, gl.TEXTURE_MAG_FILTER, gl.NEAREST );

    gl.uniform1i(gl.getUniformLocation(program, "texture5"), 5);
}

window.onload = function init() {
    canvas = document.getElementById("gl-canvas");

	var image = document.getElementById("texImage");
    var image1 = document.getElementById("texImage1");
    var image2 = document.getElementById("texImage2");
    var image3 = document.getElementById("texImage3");
    
    
    gl = WebGLUtils.setupWebGL(canvas);
    if (!gl) { alert("WebGL isn't available"); }

    gl.viewport(0, 0, canvas.width, canvas.height);
    gl.clearColor(0.5, 0.8, 1.0, 1.0);

    gl.enable(gl.DEPTH_TEST);
    
    //
    //  Load shaders and initialize attribute buffers
    //
    program = initShaders(gl, "vertex-shader", "fragment-shader");
    gl.useProgram(program);

    setPoints();
    
    // 获取viewMatrix变量的存储地址
    viewMatrixLoc = gl.getUniformLocation(program, 'viewMatrix');
    // 设置视点、视线和上方向
    viewMatrix = lookAt(vec3(0, 0.0, 2.0), vec3(0, 0, 0), vec3(0, 1, 0));
    // 将视图矩阵传递给viewMatrix变量
    gl.uniformMatrix4fv(viewMatrixLoc, false, flatten(viewMatrix));


    // 设置材质
    var ambientProduct = mult(lightAmbient, materialAmbient);
    var diffuseProduct = mult(lightDiffuse, materialDiffuse);
    var specularProduct = mult(lightSpecular, materialSpecular);
    
    // 创建缓冲区，并向缓冲区写入立方体每个面的颜色信息555555555555555555555555555
    nBuffer5 = gl.createBuffer();
    gl.bindBuffer( gl.ARRAY_BUFFER, nBuffer5 );
    gl.bufferData( gl.ARRAY_BUFFER, flatten(normals5), gl.STATIC_DRAW );
    //获取着色器中vNormal变量，并向其传递数据
    vNormal5 = gl.getAttribLocation( program, "vNormal" );
    gl.vertexAttribPointer( vNormal5, 4, gl.FLOAT, false, 0, 0 );
    gl.enableVertexAttribArray( vNormal5 );
    // 创建缓冲区，并向缓冲区写入立方体的顶点信息
    vBuffer5 = gl.createBuffer();
    gl.bindBuffer( gl.ARRAY_BUFFER, vBuffer5 );
    gl.bufferData( gl.ARRAY_BUFFER, flatten(points5), gl.STATIC_DRAW );
    // 获取着色器中vPosition变量，并向其传递数据
    vPosition5 = gl.getAttribLocation( program, "vPosition" );
    gl.vertexAttribPointer(vPosition5, 4, gl.FLOAT, false, 0, 0);
    gl.enableVertexAttribArray( vPosition5 );
    // 创建缓冲区，并向缓冲区写入纹理的顶点信息
    tBuffer5 = gl.createBuffer();
    gl.bindBuffer( gl.ARRAY_BUFFER, tBuffer5);
    gl.bufferData( gl.ARRAY_BUFFER, flatten(texCoordsArray5), gl.STATIC_DRAW);
    //获取着色器中vTexCoord变量，并向其传递数据
    vTexCoord5 = gl.getAttribLocation( program, "vTexCoord");
    gl.vertexAttribPointer( vTexCoord5, 2, gl.FLOAT, false, 0, 0);
    gl.enableVertexAttribArray(vTexCoord5);

    configureTexture5(image);

    // 创建缓冲区，并向缓冲区写入立方体每个面的颜色信息
    nBuffer1 = gl.createBuffer();
    gl.bindBuffer( gl.ARRAY_BUFFER, nBuffer1 );
    gl.bufferData( gl.ARRAY_BUFFER, flatten(normals1), gl.STATIC_DRAW );
    //获取着色器中vNormal变量，并向其传递数据
    vNormal1 = gl.getAttribLocation( program, "vNormal" );
    gl.vertexAttribPointer( vNormal1, 4, gl.FLOAT, false, 0, 0 );
    gl.enableVertexAttribArray( vNormal1 );
    // 创建缓冲区，并向缓冲区写入立方体的顶点信息
    vBuffer1 = gl.createBuffer();
    gl.bindBuffer( gl.ARRAY_BUFFER, vBuffer1 );
    gl.bufferData( gl.ARRAY_BUFFER, flatten(points1), gl.STATIC_DRAW );
    // 获取着色器中vPosition变量，并向其传递数据
    vPosition1 = gl.getAttribLocation( program, "vPosition" );
    gl.vertexAttribPointer(vPosition1, 4, gl.FLOAT, false, 0, 0);
    gl.enableVertexAttribArray( vPosition1 );
    // 创建缓冲区，并向缓冲区写入纹理的顶点信息
    tBuffer1 = gl.createBuffer();
    gl.bindBuffer( gl.ARRAY_BUFFER, tBuffer1);
    gl.bufferData( gl.ARRAY_BUFFER, flatten(texCoordsArray1), gl.STATIC_DRAW);
    //获取着色器中vTexCoord变量，并向其传递数据
    vTexCoord1 = gl.getAttribLocation( program, "vTexCoord");
    gl.vertexAttribPointer( vTexCoord1, 2, gl.FLOAT, false, 0, 0);
    gl.enableVertexAttribArray(vTexCoord1);
    
    initBody();//身体各部位初始化
    configureTexture1(image1);
    

    // 创建缓冲区，并向缓冲区写入立方体每个面的法向量信息
    nBuffer2 = gl.createBuffer();
    gl.bindBuffer( gl.ARRAY_BUFFER, nBuffer2 );
    gl.bufferData( gl.ARRAY_BUFFER, flatten(normals2), gl.STATIC_DRAW );
    //获取着色器中vNormal变量，并向其传递数据
    vNormal2 = gl.getAttribLocation( program, "vNormal" );
    gl.vertexAttribPointer( vNormal2, 4, gl.FLOAT, false, 0, 0 );
    gl.enableVertexAttribArray( vNormal2 );
    // 创建缓冲区，并向缓冲区写入立方体的顶点信息
    vBuffer2 = gl.createBuffer();
    gl.bindBuffer( gl.ARRAY_BUFFER, vBuffer2 );
    gl.bufferData( gl.ARRAY_BUFFER, flatten(points2), gl.STATIC_DRAW );
    // 获取着色器中vPosition变量，并向其传递数据
    vPosition2 = gl.getAttribLocation( program, "vPosition" );
    gl.vertexAttribPointer(vPosition2, 4, gl.FLOAT, false, 0, 0);
    gl.enableVertexAttribArray( vPosition2 );
    // 创建缓冲区，并向缓冲区写入纹理的顶点信息
    tBuffer2 = gl.createBuffer();
    gl.bindBuffer( gl.ARRAY_BUFFER, tBuffer2);
    gl.bufferData( gl.ARRAY_BUFFER, flatten(texCoordsArray2), gl.STATIC_DRAW);
    //获取着色器中vTexCoord变量，并向其传递数据
    vTexCoord2 = gl.getAttribLocation( program, "vTexCoord");
    gl.vertexAttribPointer( vTexCoord2, 2, gl.FLOAT, false, 0, 0);
    gl.enableVertexAttribArray(vTexCoord2);

    configureTexture2(image2);
   
    
   
    // 创建缓冲区，并向缓冲区写入立方体每个面的法向量信息
    nBuffer3 = gl.createBuffer();
    gl.bindBuffer( gl.ARRAY_BUFFER, nBuffer3);
    gl.bufferData( gl.ARRAY_BUFFER, flatten(normals3), gl.STATIC_DRAW );
    // 获取着色器中vNormal变量，并向其传递数据
    vNormal3 = gl.getAttribLocation( program, "vNormal" );
    gl.vertexAttribPointer( vNormal3, 4, gl.FLOAT, false, 0, 0 );
    gl.enableVertexAttribArray( vNormal3);
    // 创建缓冲区，并向缓冲区写入立方体的顶点信息
    vBuffer3 = gl.createBuffer();
    gl.bindBuffer( gl.ARRAY_BUFFER, vBuffer3 );
    gl.bufferData( gl.ARRAY_BUFFER, flatten(points3), gl.STATIC_DRAW );
    // 获取着色器中vPosition变量，并向其传递数据
    vPosition3 = gl.getAttribLocation( program, "vPosition" );
    gl.vertexAttribPointer(vPosition3, 4, gl.FLOAT, false, 0, 0);
    gl.enableVertexAttribArray( vPosition3 );
    // 创建缓冲区，并向缓冲区写入纹理的顶点信息
    tBuffer3 = gl.createBuffer();
    gl.bindBuffer( gl.ARRAY_BUFFER, tBuffer3);
    gl.bufferData( gl.ARRAY_BUFFER, flatten(texCoordsArray3), gl.STATIC_DRAW);
    //获取着色器中vTexCoord变量，并向其传递数据
    vTexCoord3 = gl.getAttribLocation( program, "vTexCoord");
    gl.vertexAttribPointer( vTexCoord3, 2, gl.FLOAT, false, 0, 0);
    gl.enableVertexAttribArray(vTexCoord3);
    
    configureTexture3(image1);
    
    // 创建缓冲区，并向缓冲区写入立方体每个面的颜色信息333333333333333333333333333333333333333333333333333333333
    nBuffer4 = gl.createBuffer();
    gl.bindBuffer( gl.ARRAY_BUFFER, nBuffer4 );
    gl.bufferData( gl.ARRAY_BUFFER, flatten(normals4), gl.STATIC_DRAW );
    //获取着色器中vNormal变量，并向其传递数据
    vNormal4 = gl.getAttribLocation( program, "vNormal" );
    gl.vertexAttribPointer( vNormal4, 4, gl.FLOAT, false, 0, 0 );
    gl.enableVertexAttribArray( vNormal4 );
    // 创建缓冲区，并向缓冲区写入立方体的顶点信息
    vBuffer4 = gl.createBuffer();
    gl.bindBuffer( gl.ARRAY_BUFFER, vBuffer4 );
    gl.bufferData( gl.ARRAY_BUFFER, flatten(points4), gl.STATIC_DRAW );
    // 获取着色器中vPosition变量，并向其传递数据
    vPosition4 = gl.getAttribLocation( program, "vPosition" );
    gl.vertexAttribPointer(vPosition4, 4, gl.FLOAT, false, 0, 0);
    gl.enableVertexAttribArray( vPosition4 );
    // 创建缓冲区，并向缓冲区写入纹理的顶点信息
    tBuffer4 = gl.createBuffer();
    gl.bindBuffer( gl.ARRAY_BUFFER, tBuffer4);
    gl.bufferData( gl.ARRAY_BUFFER, flatten(texCoordsArray4), gl.STATIC_DRAW);
    //获取着色器中vTexCoord变量，并向其传递数据
    vTexCoord4 = gl.getAttribLocation( program, "vTexCoord");
    gl.vertexAttribPointer( vTexCoord4, 2, gl.FLOAT, false, 0, 0);
    gl.enableVertexAttribArray(vTexCoord4);

    configureTexture4(image3);
    
    modelViewMatrixLoc = gl.getUniformLocation( program, "modelViewMatrix" );
    projectionMatrixLoc = gl.getUniformLocation( program, "projectionMatrix" );
    normalMatrixLoc = gl.getUniformLocation( program, "normalMatrix" );

    timedCount();
    //event listeners for buttons
    var t1;
    document.getElementById("adjustView1").onclick = function() {
    	  	
        if (viewIndex === 0) {
            viewIndex = 1;
			t1=setInterval("refreshCount()", 150);
        } else if (viewIndex === 1) {
            viewIndex = 0;
			window.clearInterval(t1);
        }
    };
    var t2;
    document.getElementById("adjustView2").onclick = function() {
    	  	
        if (viewIndex === 0) {
            viewIndex = 1;
			t2=setInterval("refreshCount2()", 50);
        } else if (viewIndex === 1) {
            viewIndex = 0;
			window.clearInterval(t2);
        }
    };
    //human1
    document.getElementById("cubeForward").onclick = function() {
        CubeTx1 += 0.1 * direct1[0];
        CubeTy1 += 0.1 * direct1[1];
        CubeTz1 += 0.1 * direct1[2];
    };
    document.getElementById("cubeBack").onclick = function() {
        CubeTx1 -= 0.1 * direct1[0];
        CubeTy1 -= 0.1 * direct1[1];
        CubeTz1 -= 0.1 * direct1[2];
    };
    document.getElementById("cubeR1").onclick = function() {
        CubeRotateAngle1 -= 5;
    };
    document.getElementById("cubeR2").onclick = function() {
        CubeRotateAngle1 += 5;
    };
    document.getElementById("small").onclick = function() {
        scalePercent1 -= 0.05;
    };
    document.getElementById("big").onclick = function() {
        scalePercent1 += 0.05;
    };

    //human2
    document.getElementById("cubeForward2").onclick = function() {
        CubeTx2 += 0.1 * direct2[0];
        CubeTy2 += 0.1 * direct2[1];
        CubeTz2 += 0.1 * direct2[2];
    };
    document.getElementById("cubeBack2").onclick = function() {
        CubeTx2 -= 0.1 * direct2[0];
        CubeTy2 -= 0.1 * direct2[1];
        CubeTz2 -= 0.1 * direct2[2];
    };
    document.getElementById("cubeR12").onclick = function() {
        CubeRotateAngle2 -= 5;
    };
    document.getElementById("cubeR22").onclick = function() {
        CubeRotateAngle2 += 5;
    };
    document.getElementById("small2").onclick = function() {
        scalePercent2 -= 0.05;
    };
    document.getElementById("big2").onclick = function() {
        scalePercent2 += 0.05;
    };
    
    // 礼物盒
    document.getElementById("cubeForward3").onclick = function() {
        CubeTx4 += 0.1 * direct4[0];
        CubeTy4 += 0.1 * direct4[1];
        CubeTz4 += 0.1 * direct4[2];
    };
    document.getElementById("cubeBack3").onclick = function() {
        CubeTx4 -= 0.1 * direct4[0];
        CubeTy4 -= 0.1 * direct4[1];
        CubeTz4 -= 0.1 * direct4[2];
    };
    document.getElementById("cubeR13").onclick = function() {
        CubeRotateAngle4 -= 5;
    };
    document.getElementById("cubeR23").onclick = function() {
        CubeRotateAngle4 += 5;
    };
    document.getElementById("small3").onclick = function() {
        scalePercent4 -= 0.05;
    };
    document.getElementById("big3").onclick = function() {
        scalePercent4 += 0.05;
    };
    
    //光源
    document.getElementById("lightLeft").onclick = function() {
        lightPosition[0] -= 0.1;
        CubeTx3 = lightPosition[0];
    };
    document.getElementById("lightRight").onclick = function() {
        lightPosition[0] += 0.1;
        CubeTx3 = lightPosition[0];
    };
    document.getElementById("lightFront").onclick = function() {
        lightPosition[2] += 0.1;
        CubeTz3 = lightPosition[2];
    };
    document.getElementById("lightBack").onclick = function() {
        lightPosition[2] -= 0.1;
        CubeTz3 = lightPosition[2];
    };
    document.getElementById("lightUp").onclick = function() {
        lightPosition[1] += 0.1;
        CubeTy3 = lightPosition[1];
    };
    document.getElementById("lightDown").onclick = function() {
        lightPosition[1] -= 0.1;
        CubeTy3 = lightPosition[1];
    };

    gl.uniform4fv( gl.getUniformLocation(program,
        "lightPosition"),flatten(lightPosition) );
    gl.uniform4fv( gl.getUniformLocation(program,
        "ambientProduct"),flatten(ambientProduct) );
    gl.uniform4fv( gl.getUniformLocation(program,
        "diffuseProduct"),flatten(diffuseProduct) );
    gl.uniform4fv( gl.getUniformLocation(program,
        "specularProduct"),flatten(specularProduct) );
    gl.uniform1f( gl.getUniformLocation(program,
        "shininess"),materialShininess );
  
    render();
}

function refreshCount() {

	a=r*Math.sin(w);
	z=r*Math.cos(w);
	w+=dr;
	viewMatrix = lookAt(vec3(a, 1.0, z), vec3(0, 0, 0), vec3(0, 1, 0));
	gl.uniformMatrix4fv(viewMatrixLoc, false, flatten(viewMatrix));
	
}

var end=0;
function refreshCount2() {
	if(end==0){
	a-=0.05;
	}
	if(a<-2){
		end=1;
	}
	if(end==1){
		a+=0.05;
	}
	if(a>2){
		end=0;
	}

	viewMatrix = lookAt(vec3(a, 1.0, 1.5), vec3(0, 0, 0), vec3(0, 1, 0));
	gl.uniformMatrix4fv(viewMatrixLoc, false, flatten(viewMatrix));
	
}

function render() {

    gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);

    projectionMatrix = perspective(fovy, aspect, near, far);
    gl.uniformMatrix4fv( projectionMatrixLoc, false, flatten(projectionMatrix) );
    
    //小人1变换
    var init = translate(-0.3, -0.15, 0); // 初始变换矩阵，用于设置模型的初始位置
    var S = scalem(scalePercent1, scalePercent1, scalePercent1);
    var T = translate(CubeTx1, CubeTy1, CubeTz1);
    var R = rotateY(CubeRotateAngle1);
    
    modelViewMatrix = mult(mult(mult(init, T), R), S);
    var m = mult(mult(T, R), S); // 用于处理正面的方向
    
    // 记录正面的方向
    direct1 = vec4( 0.0, 0.0, 1.0, 1.0 ); // 初始化初始方向
    direct1 = multMat4Vec4(m, direct1);
    
    gl.uniformMatrix4fv(modelViewMatrixLoc, false, flatten(modelViewMatrix));
    
    normalMatrix = modelViewMatrix;
    gl.uniformMatrix4fv(normalMatrixLoc, false, flatten(normalMatrix));
    
    gl.bindBuffer(gl.ARRAY_BUFFER, vBuffer1);
    gl.vertexAttribPointer(vPosition1, 4, gl.FLOAT, false, 0, 0);
    
    // 设置材质
    materialAmbient = vec4( 1.0, 1.0, 0.5, 1.0 );
    materialDiffuse = vec4( 1.0, 0.8, 0.0, 1.0);
    materialSpecular = vec4( 1.0, 1.0, 1.0, 1.0 );
    materialShininess = 100.0;
    var ambientProduct = mult(lightAmbient, materialAmbient);
    var diffuseProduct = mult(lightDiffuse, materialDiffuse);
    var specularProduct = mult(lightSpecular, materialSpecular);
    gl.uniform4fv( gl.getUniformLocation(program,
        "ambientProduct"),flatten(ambientProduct) );
    gl.uniform4fv( gl.getUniformLocation(program,
        "diffuseProduct"),flatten(diffuseProduct) );
    gl.uniform4fv( gl.getUniformLocation(program,
        "specularProduct"),flatten(specularProduct) );
    gl.uniform4fv( gl.getUniformLocation(program,
        "lightPosition"),flatten(lightPosition) );
    gl.uniform1f( gl.getUniformLocation(program,
        "shininess"),materialShininess );

    gl.bindBuffer( gl.ARRAY_BUFFER, vBuffer1 );
    gl.vertexAttribPointer(vPosition1, 4, gl.FLOAT, false, 0, 0);
    gl.enableVertexAttribArray( vPosition1 );

    gl.bindBuffer( gl.ARRAY_BUFFER, nBuffer1);
    gl.vertexAttribPointer( vNormal1, 4, gl.FLOAT, false, 0, 0 );
    gl.enableVertexAttribArray( vNormal1);
    
    gl.bindBuffer( gl.ARRAY_BUFFER, tBuffer1);
    gl.vertexAttribPointer( vTexCoord1, 2, gl.FLOAT, false, 0, 0);
    gl.uniform1i(gl.getUniformLocation(program, "bTexCoord"), 1);
    gl.activeTexture(gl.TEXTURE1);
    gl.enableVertexAttribArray(vTexCoord1);
    
    gl.drawArrays(gl.TRIANGLES, 0, 36*3);
    
    bodyMove();
    
    //小人2变换
    init = translate(0.3, -0.15, 0); // 初始变换矩阵，用于设置模型的初始位置
    S = scalem(scalePercent2, scalePercent2, scalePercent2);
    T = translate(CubeTx2, CubeTy2, CubeTz2);
    R = rotateY(CubeRotateAngle2);
    
    modelViewMatrix = mult(mult(mult(init, T), R), S);
    m = mult(mult(T, R), S);
    
    // 记录正面的方向
    direct2 = vec4( 0.0, 0.0, 1.0, 1.0 ); // 初始化初始方向
    direct2 = multMat4Vec4(m, direct2);
    
    gl.uniformMatrix4fv(modelViewMatrixLoc, false, flatten(modelViewMatrix));
    
    normalMatrix = modelViewMatrix;
    gl.uniformMatrix4fv(normalMatrixLoc, false, flatten(normalMatrix));
    
    gl.bindBuffer(gl.ARRAY_BUFFER, vBuffer2);
    gl.vertexAttribPointer(vPosition2, 4, gl.FLOAT, false, 0, 0);
    
    // 设置新材质
    materialAmbient = vec4( 1.0, 0.0, 1.0, 1.0 );
    materialDiffuse = vec4( 1.0, 0.5, 0.5, 1.0);
    materialSpecular = vec4( 1.0, 0.5, 0.0, 1.0 );
    materialShininess = 100.0;
    ambientProduct = mult(lightAmbient, materialAmbient);
    diffuseProduct = mult(lightDiffuse, materialDiffuse);
    specularProduct = mult(lightSpecular, materialSpecular);
    gl.uniform4fv( gl.getUniformLocation(program,
        "ambientProduct"),flatten(ambientProduct) );
    gl.uniform4fv( gl.getUniformLocation(program,
        "diffuseProduct"),flatten(diffuseProduct) );
    gl.uniform4fv( gl.getUniformLocation(program,
        "specularProduct"),flatten(specularProduct) );
    gl.uniform1f( gl.getUniformLocation(program,
        "shininess"),materialShininess );

    gl.bindBuffer( gl.ARRAY_BUFFER, vBuffer2 );
    gl.vertexAttribPointer(vPosition2, 4, gl.FLOAT, false, 0, 0);
    gl.enableVertexAttribArray( vPosition2 );

    gl.bindBuffer( gl.ARRAY_BUFFER, nBuffer2);
    gl.vertexAttribPointer( vNormal2, 4, gl.FLOAT, false, 0, 0 );
    gl.enableVertexAttribArray( vNormal2);
    
    gl.bindBuffer( gl.ARRAY_BUFFER, tBuffer2);
    gl.vertexAttribPointer( vTexCoord2, 2, gl.FLOAT, false, 0, 0);
    gl.uniform1i(gl.getUniformLocation(program, "bTexCoord"), 2);
    gl.activeTexture(gl.TEXTURE2);
    gl.enableVertexAttribArray(vTexCoord2);

    gl.drawArrays(gl.TRIANGLES, 0, 36*6);
    
    // 盒子变换
    init = translate(0, -0.2, 0); // 初始变换矩阵，用于设置模型的初始位置
    S = scalem(scalePercent4, scalePercent4, scalePercent4);
    T = translate(CubeTx4, CubeTy4, CubeTz4);
    R = rotateY(CubeRotateAngle4);
    
    modelViewMatrix = mult(mult(mult(init, T), R), S);
    m = mult(mult(T, R), S);
    
    // 记录正面的方向
    direct4 = vec4( 0.0, 0.0, 1.0, 1.0 ); // 初始化初始方向
    direct4 = multMat4Vec4(m, direct4);
    
    gl.uniformMatrix4fv(modelViewMatrixLoc, false, flatten(modelViewMatrix));
    
    normalMatrix = modelViewMatrix;
    gl.uniformMatrix4fv(normalMatrixLoc, false, flatten(normalMatrix));
    
    // 盒子顶点
    gl.bindBuffer(gl.ARRAY_BUFFER, vBuffer4);
    gl.vertexAttribPointer(vPosition4, 4, gl.FLOAT, false, 0, 0);
    
    // 设置新材质
    materialAmbient = vec4( 1.0, 1.0, 1.0, 1.0 );
    materialDiffuse = vec4( 1.0, 1.0, 1.0, 1.0);
    materialSpecular = vec4( 1.0, 1.0, 1.0, 1.0 );
    materialShininess = 100.0;
    ambientProduct = mult(lightAmbient, materialAmbient);
    diffuseProduct = mult(lightDiffuse, materialDiffuse);
    specularProduct = mult(lightSpecular, materialSpecular);
    gl.uniform4fv( gl.getUniformLocation(program,
        "ambientProduct"),flatten(ambientProduct) );
    gl.uniform4fv( gl.getUniformLocation(program,
        "diffuseProduct"),flatten(diffuseProduct) );
    gl.uniform4fv( gl.getUniformLocation(program,
        "specularProduct"),flatten(specularProduct) );
    gl.uniform1f( gl.getUniformLocation(program,
        "shininess"),materialShininess );

    gl.bindBuffer( gl.ARRAY_BUFFER, vBuffer4 );
    gl.vertexAttribPointer(vPosition4, 4, gl.FLOAT, false, 0, 0);
    gl.enableVertexAttribArray( vPosition4 );

    gl.bindBuffer( gl.ARRAY_BUFFER, nBuffer4);
    gl.vertexAttribPointer( vNormal4, 4, gl.FLOAT, false, 0, 0 );
    gl.enableVertexAttribArray( vNormal4);

    gl.bindBuffer( gl.ARRAY_BUFFER, tBuffer4);
    gl.vertexAttribPointer( vTexCoord4, 2, gl.FLOAT, false, 0, 0);
    gl.uniform1i(gl.getUniformLocation(program, "bTexCoord"), 4);
    gl.activeTexture(gl.TEXTURE4);
    gl.enableVertexAttribArray(vTexCoord4);
    
    gl.drawArrays(gl.TRIANGLES, 0, 36);
    
    //地面
    modelViewMatrix = translate(0, -0.32, 0);
    gl.uniformMatrix4fv(modelViewMatrixLoc, false, flatten(modelViewMatrix));

    normalMatrix = modelViewMatrix;
    gl.uniformMatrix4fv(normalMatrixLoc, false, flatten(normalMatrix));

	 // 设置新材质
    materialAmbient = vec4( 1.0, 0.0, 1.0, 1.0 );
    materialDiffuse = vec4( 1.0, 0.5, 0.5, 1.0);
    materialSpecular = vec4( 1.0, 0.5, 0.0, 1.0 );
    materialShininess = 100.0;
    ambientProduct = mult(lightAmbient, materialAmbient);
    diffuseProduct = mult(lightDiffuse, materialDiffuse);
    specularProduct = mult(lightSpecular, materialSpecular);
    gl.uniform4fv( gl.getUniformLocation(program,
        "ambientProduct"),flatten(ambientProduct) );
    gl.uniform4fv( gl.getUniformLocation(program,
        "diffuseProduct"),flatten(diffuseProduct) );
    gl.uniform4fv( gl.getUniformLocation(program,
        "specularProduct"),flatten(specularProduct) );
    gl.uniform1f( gl.getUniformLocation(program,
        "shininess"),materialShininess );
        
    gl.bindBuffer( gl.ARRAY_BUFFER, vBuffer5 );
    gl.vertexAttribPointer(vPosition5, 4, gl.FLOAT, false, 0, 0);
    gl.enableVertexAttribArray( vPosition5 );

    gl.bindBuffer( gl.ARRAY_BUFFER, nBuffer5);
    gl.vertexAttribPointer( vNormal5, 4, gl.FLOAT, false, 0, 0 );
    gl.enableVertexAttribArray( vNormal5);

    gl.bindBuffer( gl.ARRAY_BUFFER, tBuffer5);
    gl.vertexAttribPointer( vTexCoord5, 2, gl.FLOAT, false, 0, 0);
    gl.uniform1i(gl.getUniformLocation(program, "bTexCoord"), 5);
    gl.activeTexture(gl.TEXTURE5);
    gl.enableVertexAttribArray(vTexCoord5);
    gl.drawArrays(gl.TRIANGLES, 0, 36*50*50);

    // 光源变换
    S = scalem(scalePercent3, scalePercent3, scalePercent3);
    T = translate(CubeTx3, CubeTy3, CubeTz3);
    
    modelViewMatrix = mult(T, S);
    gl.uniformMatrix4fv(modelViewMatrixLoc, false, flatten(modelViewMatrix));
    
    normalMatrix = modelViewMatrix;
    gl.uniformMatrix4fv(normalMatrixLoc, false, flatten(normalMatrix));
    
    // 设置新材质
    materialAmbient = vec4( 1.0, 0.0, 1.0, 1.0 );
    materialDiffuse = vec4( 1.0, 0.8, 0.0, 1.0);
    materialSpecular = vec4( 1.0, 1.0, 0.0, 1.0 );
    materialShininess = 20.0;
    ambientProduct = mult(lightAmbient, materialAmbient);
    diffuseProduct = mult(lightDiffuse, materialDiffuse);
    specularProduct = mult(lightSpecular, materialSpecular);
    gl.uniform4fv( gl.getUniformLocation(program,
        "ambientProduct"),flatten(ambientProduct) );
    gl.uniform4fv( gl.getUniformLocation(program,
        "diffuseProduct"),flatten(diffuseProduct) );
    gl.uniform4fv( gl.getUniformLocation(program,
        "specularProduct"),flatten(specularProduct) );
    gl.uniform1f( gl.getUniformLocation(program,
        "shininess"),materialShininess );

    gl.bindBuffer( gl.ARRAY_BUFFER, vBuffer3 );
    gl.vertexAttribPointer(vPosition3, 4, gl.FLOAT, false, 0, 0);
    gl.enableVertexAttribArray( vPosition3 );

    gl.bindBuffer( gl.ARRAY_BUFFER, nBuffer3);
    gl.vertexAttribPointer( vNormal3, 4, gl.FLOAT, false, 0, 0 );
    gl.enableVertexAttribArray( vNormal3);
    
    gl.bindBuffer( gl.ARRAY_BUFFER, tBuffer3);
    gl.vertexAttribPointer( vTexCoord3, 2, gl.FLOAT, false, 0, 0);
    gl.uniform1i(gl.getUniformLocation(program, "bTexCoord"), 3);
    gl.activeTexture(gl.TEXTURE3);
    gl.enableVertexAttribArray(vTexCoord3);
    
    gl.drawArrays(gl.TRIANGLES, 0, 36);
    

    window.requestAnimFrame(render);
}

function setPoints() {
    drawhuman1(points1, normals1, texCoordsArray1);
    drawlefthand(points_1, normals_1,texCoordsArray_1); // 左手臂
    drawrighthand(points_2, normals_2,texCoordsArray_2); // 右手臂
    drawleftleg(points_3, normals_3,texCoordsArray_3); // 左腿
    drawrightleg(points_4, normals_4,texCoordsArray_4); // 右腿
    drawhuman2(points2, normals2, texCoordsArray2);
    drawLight(points3, normals3, texCoordsArray3); // 光源
    drawBox(points4, normals4, texCoordsArray4); 
    for(var x = -50;x < 50;x=x+2){
        for(var z = -50;z < 50;z=z+2){
            floor(points5, normals5, texCoordsArray5, x, z);//地面
        }
    }
}

function quadPush(texCoordsArray){//输入一个矩形的空纹理坐标
    texCoordsArray.push(texCoord[0]);
    texCoordsArray.push(texCoord[1]);
    texCoordsArray.push(texCoord[2]);
    texCoordsArray.push(texCoord[0]);
    texCoordsArray.push(texCoord[2]);
    texCoordsArray.push(texCoord[3]);
}

function quadPushTCNULL(texCoordsArray){//输入一个矩形的空纹理坐标
    texCoordsArray.push(texCoord[0]);
    texCoordsArray.push(texCoord[0]);
    texCoordsArray.push(texCoord[0]);
    texCoordsArray.push(texCoord[0]);
    texCoordsArray.push(texCoord[0]);
    texCoordsArray.push(texCoord[0]);
}

function quad(vertices, a, b, c, d, pointArray, normalArray) {
    var t1 = subtract(vertices[b], vertices[a]);
    var t2 = subtract(vertices[c], vertices[b]);
    var normal = cross(t1, t2);
    normal = vec4(normal[0], normal[1], normal[2], 0.0);

    pointArray.push(vertices[a]);
    normalArray.push(normal);
    pointArray.push(vertices[b]);
    normalArray.push(normal);
    pointArray.push(vertices[c]);
    normalArray.push(normal);
    pointArray.push(vertices[a]);
    normalArray.push(normal);
    pointArray.push(vertices[c]);
    normalArray.push(normal);
    pointArray.push(vertices[d]);
    normalArray.push(normal);
}

// 绘制光源
function drawLight(pointArray, normalArray, texCoordsArray) {
    // 光源的八个顶点(x,y,z,a)
    var lightVertices = [
        vec4(-0.01, -0.01, 0.01, 1.0),
        vec4(-0.01, 0.01, 0.01, 1.0),
        vec4(0.01, 0.01, 0.01, 1.0),
        vec4(0.01, -0.01, 0.01, 1.0),
        vec4(-0.01, -0.01, -0.01, 1.0),
        vec4(-0.01, 0.01, -0.01, 1.0),
        vec4(0.01, 0.01, -0.01, 1.0),
        vec4(0.01, -0.01, -0.01, 1.0)
    ];
    quad(lightVertices, 1, 0, 3, 2, pointArray, normalArray);
    quad(lightVertices, 2, 3, 7, 6, pointArray, normalArray);
    quad(lightVertices, 3, 0, 4, 7, pointArray, normalArray);
    quad(lightVertices, 6, 5, 1, 2, pointArray, normalArray);
    quad(lightVertices, 4, 5, 6, 7, pointArray, normalArray);
    quad(lightVertices, 5, 4, 0, 1, pointArray, normalArray);
    for(var i = 0; i < 6;i++){
        quadPush(texCoordsArray);
    }
}

//地面
function floor(points, normals, texCoordsArray, x, z){//x,z为地面平移的距离
    // 地面的八个顶点(x,y,z,a)
    var floorVertices = [
        vec4(-1.0 + x, -0.01, 1.0 + z, 1.0),
        vec4(-1.0 + x, 0.0, 1.0 + z, 1.0),
        vec4(1.0 + x, 0.0, 1.0 + z, 1.0),
        vec4(1.0 + x, -0.01, 1.0 + z, 1.0),
        vec4(-1.0 + x, -0.01, -1.0 + z, 1.0),
        vec4(-1.0 + x, 0.0, -1.0 + z, 1.0),
        vec4(1.0 + x, 0.0, -1.0 + z, 1.0),
        vec4(1.0 + x, -0.01, -1.0 + z, 1.0)
    ];
    quad(floorVertices, 1, 0, 3, 2, points, normals);
    quad(floorVertices, 2, 3, 7, 6, points, normals);
    quad(floorVertices, 3, 0, 4, 7, points, normals);
    quad(floorVertices, 6, 5, 1, 2, points, normals);
    quad(floorVertices, 4, 5, 6, 7, points, normals);
    quad(floorVertices, 5, 4, 0, 1, points, normals);
    for(var i = 0; i < 6;i++){
        quadPush(texCoordsArray);
    }
}

//礼物盒
function drawBox(pointArray, normalArray, texCoordsArray) {
    var lightVertices = [
        vec4(-0.2, -0.2, 0.2, 1.0),
        vec4(-0.2, 0.2, 0.2, 1.0),
        vec4(0.2, 0.2, 0.2, 1.0),
        vec4(0.2, -0.2, 0.2, 1.0),
        vec4(-0.2, -0.2, -0.2, 1.0),
        vec4(-0.2, 0.2, -0.2, 1.0),
        vec4(0.2, 0.2, -0.2, 1.0),
        vec4(0.2, -0.2, -0.2, 1.0)
    ];
    quad(lightVertices, 1, 0, 3, 2, pointArray, normalArray);
    quad(lightVertices, 2, 3, 7, 6, pointArray, normalArray);
    quad(lightVertices, 3, 0, 4, 7, pointArray, normalArray);
    quad(lightVertices, 6, 5, 1, 2, pointArray, normalArray);
    quad(lightVertices, 4, 5, 6, 7, pointArray, normalArray);
    quad(lightVertices, 5, 4, 0, 1, pointArray, normalArray);
    for(var i = 0;i < 3;i++){
        quadPushTCNULL(texCoordsArray);
    }
    var texCoordface = [
        vec2(0.0, 0.0),
        vec2(0.0, 1.0),
        vec2(1.0, 1.0),
        vec2(1.0, 0.0)
    ];
    texCoordsArray.push(texCoordface[2]);
    texCoordsArray.push(texCoordface[3]);
    texCoordsArray.push(texCoordface[0]);
    texCoordsArray.push(texCoordface[2]);
    texCoordsArray.push(texCoordface[0]);
    texCoordsArray.push(texCoordface[1]);
    for(var i = 0;i < 2;i++){
        quadPushTCNULL(texCoordsArray);
    }
}

function drawhuman1(points, normals, texCoordsArray) {
    drawhead(points, normals,texCoordsArray);
    drawbody(points, normals,texCoordsArray);
}

// 绘制头
function drawhead(pointArray, normalArray, texCoordsArray) {
    var vertices = [
        vec4(  -0.15,0.2,0.15,1.0),
        vec4( -0.15,0.4,0.15,1.0 ),
        vec4(  0.15,0.4,0.15,1.0 ),
        vec4(  0.15,0.2,0.15,1.0 ),
        vec4( -0.15,0.2,-0.15,1.0 ),
        vec4( -0.15,0.4,-0.15,1.0 ),
        vec4(  0.15,0.4,-0.15,1.0 ),
        vec4(  0.15,0.2,-0.15,1.0 )
    ];
    quad(vertices, 1, 0, 3, 2, pointArray, normalArray);
	quad(vertices, 1, 0, 4, 5, pointArray, normalArray);
	quad(vertices, 5, 4, 7, 6, pointArray, normalArray);
	quad(vertices, 2, 3, 7, 6, pointArray, normalArray);
	quad(vertices, 1, 5, 6, 2, pointArray, normalArray);
	quad(vertices, 0, 4, 7, 3, pointArray, normalArray);
	var texCoordface = [
        vec2(0.0, 0.0),
        vec2(0.0, 1.0),
        vec2(1.0, 1.0),
        vec2(1.0, 0.0)
    ];
    texCoordsArray.push(texCoordface[2]);
    texCoordsArray.push(texCoordface[3]);
    texCoordsArray.push(texCoordface[0]);
    texCoordsArray.push(texCoordface[2]);
    texCoordsArray.push(texCoordface[0]);
    texCoordsArray.push(texCoordface[1]);
    for(var i = 0;i < 5;i++){
        quadPushTCNULL(texCoordsArray);
    }
}

// 绘制身体
function drawbody(pointArray, normalArray, texCoordsArray) {
    var vertices = [
        vec4(  -0.1,-0.1,0.1,1.0 ),
        vec4( -0.1,0.2,0.1,1.0 ),
        vec4(  0.1,0.2,0.1,1.0 ),
        vec4(  0.1,-0.1,0.1,1.0 ),
        vec4( -0.1,-0.1,-0.1,1.0 ),
        vec4( -0.1,0.2,-0.1,1.0 ),
        vec4(  0.1,0.2,-0.1,1.0 ),
        vec4(  0.1,-0.1,-0.1,1.0 )
    ];
    quad(vertices,1,0,3,2, pointArray, normalArray);
	quad(vertices,1,0,4,5, pointArray, normalArray);
	quad(vertices,5,4,7,6, pointArray, normalArray);
	quad(vertices,2,3,7,6, pointArray, normalArray);
	quad(vertices,1,5,6,2, pointArray, normalArray);
	quad(vertices,0,4,7,3, pointArray, normalArray);
	for(var i = 0;i < 6;i++){
        quadPushTCNULL(texCoordsArray);
    }
}

// 绘制左手
function drawlefthand(pointArray, normalArray, texCoordsArray) {
    var vertices = [
        vec4(  -0.1,-0.3,0.075,1.0 ),
        vec4( -0.1,-0.1,0.075,1.0 ),
        vec4(  -0.025,-0.1,0.075,1.0 ),
        vec4(  -0.025,-0.3,0.075,1.0 ),
        vec4( -0.1,-0.3,-0.075,1.0 ),
        vec4( -0.1,-0.1,-0.075,1.0 ),
        vec4(  -0.025,-0.1,-0.075,1.0 ),
        vec4(  -0.025,-0.3,-0.075,1.0 )
    ];
    quad(vertices,1,0,3,2, pointArray, normalArray);
	quad(vertices,1,0,4,5, pointArray, normalArray);
	quad(vertices,5,4,7,6, pointArray, normalArray);
	quad(vertices,2,3,7,6, pointArray, normalArray);
	quad(vertices,1,5,6,2, pointArray, normalArray);
	quad(vertices,0,4,7,3, pointArray, normalArray);
	for(var i = 0;i < 6;i++){
        quadPushTCNULL(texCoordsArray);
    }
}

// 绘制右手
function drawrighthand(pointArray, normalArray, texCoordsArray) {
    var vertices = [
        vec4(  0.025,-0.3,0.075,1.0 ),
        vec4( 0.025,-0.1,0.075,1.0 ),
        vec4(  0.1,-0.1,0.075,1.0 ),
        vec4(  0.1,-0.3,0.075,1.0 ),
        vec4( 0.025,-0.3,-0.075,1.0 ),
        vec4( 0.025,-0.1,-0.075,1.0 ),
        vec4(  0.1,-0.1,-0.075,1.0 ),
        vec4(  0.1,-0.3,-0.075,1.0 )
    ];
    quad(vertices,1,0,3,2, pointArray, normalArray);
	quad(vertices,1,0,4,5, pointArray, normalArray);
	quad(vertices,5,4,7,6, pointArray, normalArray);
	quad(vertices,2,3,7,6, pointArray, normalArray);
	quad(vertices,1,5,6,2, pointArray, normalArray);
	quad(vertices,0,4,7,3, pointArray, normalArray);
	for(var i = 0;i < 6;i++){
        quadPushTCNULL(texCoordsArray);
    }
}

//绘制左腿
function drawleftleg(pointArray, normalArray, texCoordsArray) {
    var vertices = [
        vec4(  -0.225,-0.00,0.06,1.0 ),
        vec4( -0.175,0.17,0.06,1.0 ),
        vec4(  -0.1,0.15,0.06,1.0 ),
        vec4(  -0.15,-0.03,0.06,1.0 ),
        vec4( -0.225,-0.00,-0.06,1.0 ),
        vec4( -0.175,0.17,-0.06,1.0 ),
        vec4(  -0.1,0.15,-0.06,1.0 ),
        vec4(  -0.15,-0.03,-0.06,1.0 )
    ];
    quad(vertices,1,0,3,2, pointArray, normalArray);
	quad(vertices,1,0,4,5, pointArray, normalArray);
	quad(vertices,5,4,7,6, pointArray, normalArray);
	quad(vertices,2,3,7,6, pointArray, normalArray);
	quad(vertices,1,5,6,2, pointArray, normalArray);
	quad(vertices,0,4,7,3, pointArray, normalArray);
	for(var i = 0;i < 6;i++){
        quadPushTCNULL(texCoordsArray);
    }
}

//绘制右腿
function drawrightleg(pointArray, normalArray, texCoordsArray) {
    var vertices = [
        vec4(  0.15,-0.05,0.06,1.0 ),
        vec4( 0.1,0.15,0.06,1.0 ),
        vec4(  0.175,0.17,0.06,1.0 ),
        vec4(  0.225,-0.03,0.06,1.0 ),
        vec4( 0.15,-0.05,-0.06,1.0 ),
        vec4( 0.1,0.15,-0.06,1.0 ),
        vec4(  0.175,0.17,-0.06,1.0 ),
        vec4(  0.225,-0.03,-0.06,1.0 )
    ];
    quad(vertices,1,0,3,2, pointArray, normalArray);
	quad(vertices,1,0,4,5, pointArray, normalArray);
	quad(vertices,5,4,7,6, pointArray, normalArray);
	quad(vertices,2,3,7,6, pointArray, normalArray);
	quad(vertices,1,5,6,2, pointArray, normalArray);
	quad(vertices,0,4,7,3, pointArray, normalArray);
	for(var i = 0;i < 6;i++){
        quadPushTCNULL(texCoordsArray);
    }
}

function drawhuman2(pointArray, normalArray, texCoordsArray) {
    var vertices = [
        vec4(  -0.15,0.2,0.15,1.0),
        vec4( -0.15,0.4,0.15,1.0 ),
        vec4(  0.15,0.4,0.15,1.0 ),
        vec4(  0.15,0.2,0.15,1.0 ),
        vec4( -0.15,0.2,-0.15,1.0 ),
        vec4( -0.15,0.4,-0.15,1.0 ),
        vec4(  0.15,0.4,-0.15,1.0 ),
        vec4(  0.15,0.2,-0.15,1.0 ),
        
        vec4(  -0.1,-0.1,0.1,1.0 ),
        vec4( -0.1,0.2,0.1,1.0 ),
        vec4(  0.1,0.2,0.1,1.0 ),
        vec4(  0.1,-0.1,0.1,1.0 ),
        vec4( -0.1,-0.1,-0.1,1.0 ),
        vec4( -0.1,0.2,-0.1,1.0 ),
        vec4(  0.1,0.2,-0.1,1.0 ),
        vec4(  0.1,-0.1,-0.1,1.0 ),
        
        vec4(  -0.1,-0.3,0.075,1.0 ),
        vec4( -0.1,-0.1,0.075,1.0 ),
        vec4(  -0.025,-0.1,0.075,1.0 ),
        vec4(  -0.025,-0.3,0.075,1.0 ),
        vec4( -0.1,-0.3,-0.075,1.0 ),
        vec4( -0.1,-0.1,-0.075,1.0 ),
        vec4(  -0.025,-0.1,-0.075,1.0 ),
        vec4(  -0.025,-0.3,-0.075,1.0 ),
        
        vec4(  0.025,-0.3,0.075,1.0 ),
        vec4( 0.025,-0.1,0.075,1.0 ),
        vec4(  0.1,-0.1,0.075,1.0 ),
        vec4(  0.1,-0.3,0.075,1.0 ),
        vec4( 0.025,-0.3,-0.075,1.0 ),
        vec4( 0.025,-0.1,-0.075,1.0 ),
        vec4(  0.1,-0.1,-0.075,1.0 ),
        vec4(  0.1,-0.3,-0.075,1.0 ),
        //手
        vec4(  -0.225,-0.00,0.06,1.0 ),
        vec4( -0.175,0.17,0.06,1.0 ),
        vec4(  -0.1,0.15,0.06,1.0 ),
        vec4(  -0.15,-0.03,0.06,1.0 ),
        vec4( -0.225,-0.00,-0.06,1.0 ),
        vec4( -0.175,0.17,-0.06,1.0 ),
        vec4(  -0.1,0.15,-0.06,1.0 ),
        vec4(  -0.15,-0.03,-0.06,1.0 ),
        
        vec4(  0.15,-0.05,0.06,1.0 ),
        vec4( 0.1,0.15,0.06,1.0 ),
        vec4(  0.175,0.17,0.06,1.0 ),
        vec4(  0.225,-0.03,0.06,1.0 ),
        vec4( 0.15,-0.05,-0.06,1.0 ),
        vec4( 0.1,0.15,-0.06,1.0 ),
        vec4(  0.175,0.17,-0.06,1.0 ),
        vec4(  0.225,-0.03,-0.06,1.0 )
    ];
    quad(vertices, 1, 0, 3, 2, pointArray, normalArray);
	quad(vertices, 1, 0, 4, 5, pointArray, normalArray);
	quad(vertices, 5, 4, 7, 6, pointArray, normalArray);
	quad(vertices, 2, 3, 7, 6, pointArray, normalArray);
	quad(vertices, 1, 5, 6, 2, pointArray, normalArray);
	quad(vertices, 0, 4, 7, 3, pointArray, normalArray);
	var texCoordface = [
        vec2(0.0, 0.0),
        vec2(0.0, 1.0),
        vec2(1.0, 1.0),
        vec2(1.0, 0.0)
    ];
    texCoordsArray.push(texCoordface[2]);
    texCoordsArray.push(texCoordface[3]);
    texCoordsArray.push(texCoordface[0]);
    texCoordsArray.push(texCoordface[2]);
    texCoordsArray.push(texCoordface[0]);
    texCoordsArray.push(texCoordface[1]);
    for(var i = 0;i < 5;i++){
        quadPushTCNULL(texCoordsArray);
    }
	
	quad(vertices,9,8,11,10, pointArray, normalArray);
	quad(vertices,9,8,12,13, pointArray, normalArray);
	quad(vertices,13,12,15,14, pointArray, normalArray);
	quad(vertices,10,11,15,14, pointArray, normalArray);
	quad(vertices,9,13,14,10, pointArray, normalArray);
	quad(vertices,8,12,15,11, pointArray, normalArray);
	for(var i = 0;i < 6;i++){
        quadPushTCNULL(texCoordsArray);
    }
	
	quad(vertices,17,16,19,18, pointArray, normalArray);
	quad(vertices,17,16,20,21, pointArray, normalArray);
	quad(vertices,21,20,23,22, pointArray, normalArray);
	quad(vertices,18,19,23,22, pointArray, normalArray);
	quad(vertices,17,21,22,18, pointArray, normalArray);
	quad(vertices,16,20,23,19, pointArray, normalArray);
	for(var i = 0;i < 6;i++){
        quadPushTCNULL(texCoordsArray);
    }
	
	quad(vertices,25,24,27,26, pointArray, normalArray);
	quad(vertices,25,24,28,29, pointArray, normalArray);
	quad(vertices,29,28,31,30, pointArray, normalArray);
	quad(vertices,26,27,31,30, pointArray, normalArray);
	quad(vertices,25,29,30,26, pointArray, normalArray);
	quad(vertices,24,28,31,27, pointArray, normalArray);
	for(var i = 0;i < 6;i++){
        quadPushTCNULL(texCoordsArray);
    }
	
	quad(vertices,33,32,35,34, pointArray, normalArray);
	quad(vertices,33,32,36,37, pointArray, normalArray);
	quad(vertices,37,36,39,38, pointArray, normalArray);
	quad(vertices,34,35,39,38, pointArray, normalArray);
	quad(vertices,33,37,38,34, pointArray, normalArray);
	quad(vertices,32,36,39,35, pointArray, normalArray);
	for(var i = 0;i < 6;i++){
        quadPushTCNULL(texCoordsArray);
    }
	
	quad(vertices,41,40,43,42, pointArray, normalArray);
	quad(vertices,41,40,44,45, pointArray, normalArray);
	quad(vertices,45,44,47,46, pointArray, normalArray);
	quad(vertices,42,43,47,46, pointArray, normalArray);
	quad(vertices,41,45,46,42, pointArray, normalArray);
	quad(vertices,40,44,47,43, pointArray, normalArray);
	for(var i = 0;i < 6;i++){
        quadPushTCNULL(texCoordsArray);
    }
}

function initBody(){
    // 创建缓冲区，并向缓冲区写入立方体每个面的法向量信息11111111111111111111111111111左手臂
    nBuffer_1 = gl.createBuffer();
    gl.bindBuffer( gl.ARRAY_BUFFER, nBuffer_1);
    gl.bufferData( gl.ARRAY_BUFFER, flatten(normals_1), gl.STATIC_DRAW );
    // 获取着色器中vNormal变量，并向其传递数据
    vNormal_1 = gl.getAttribLocation( program, "vNormal" );
    gl.vertexAttribPointer( vNormal_1, 4, gl.FLOAT, false, 0, 0 );
    gl.enableVertexAttribArray( vNormal_1);
    // 创建缓冲区，并向缓冲区写入立方体的顶点信息
    vBuffer_1 = gl.createBuffer();
    gl.bindBuffer( gl.ARRAY_BUFFER, vBuffer_1 );
    gl.bufferData( gl.ARRAY_BUFFER, flatten(points_1), gl.STATIC_DRAW );
    // 获取着色器中vPosition变量，并向其传递数据
    vPosition_1 = gl.getAttribLocation( program, "vPosition" );
    gl.vertexAttribPointer(vPosition_1, 4, gl.FLOAT, false, 0, 0);
    gl.enableVertexAttribArray( vPosition_1 );
    // 创建缓冲区，并向缓冲区写入纹理的顶点信息
    tBuffer_1 = gl.createBuffer();
    gl.bindBuffer( gl.ARRAY_BUFFER, tBuffer_1);
    gl.bufferData( gl.ARRAY_BUFFER, flatten(texCoordsArray_1), gl.STATIC_DRAW);
    //获取着色器中vTexCoord变量，并向其传递数据
    vTexCoord_1 = gl.getAttribLocation( program, "vTexCoord");
    gl.vertexAttribPointer( vTexCoord_1, 2, gl.FLOAT, false, 0, 0);
    gl.enableVertexAttribArray(vTexCoord_1);

    // 创建缓冲区，并向缓冲区写入立方体每个面的法向量信息11111111111111111111111111111右手臂
    nBuffer_2 = gl.createBuffer();
    gl.bindBuffer( gl.ARRAY_BUFFER, nBuffer_2);
    gl.bufferData( gl.ARRAY_BUFFER, flatten(normals_2), gl.STATIC_DRAW );
    // 获取着色器中vNormal变量，并向其传递数据
    vNormal_2 = gl.getAttribLocation( program, "vNormal" );
    gl.vertexAttribPointer( vNormal_2, 4, gl.FLOAT, false, 0, 0 );
    gl.enableVertexAttribArray( vNormal_2);
    // 创建缓冲区，并向缓冲区写入立方体的顶点信息
    vBuffer_2 = gl.createBuffer();
    gl.bindBuffer( gl.ARRAY_BUFFER, vBuffer_2 );
    gl.bufferData( gl.ARRAY_BUFFER, flatten(points_2), gl.STATIC_DRAW );
    // 获取着色器中vPosition变量，并向其传递数据
    vPosition_2 = gl.getAttribLocation( program, "vPosition" );
    gl.vertexAttribPointer(vPosition_2, 4, gl.FLOAT, false, 0, 0);
    gl.enableVertexAttribArray( vPosition_2 );
    // 创建缓冲区，并向缓冲区写入纹理的顶点信息
    tBuffer_2 = gl.createBuffer();
    gl.bindBuffer( gl.ARRAY_BUFFER, tBuffer_2);
    gl.bufferData( gl.ARRAY_BUFFER, flatten(texCoordsArray_2), gl.STATIC_DRAW);
    //获取着色器中vTexCoord变量，并向其传递数据
    vTexCoord_2 = gl.getAttribLocation( program, "vTexCoord");
    gl.vertexAttribPointer( vTexCoord_2, 2, gl.FLOAT, false, 0, 0);
    gl.enableVertexAttribArray(vTexCoord_2);

     // 创建缓冲区，并向缓冲区写入立方体每个面的法向量信息11111111111111111111111111111左脚
     nBuffer_3 = gl.createBuffer();
     gl.bindBuffer( gl.ARRAY_BUFFER, nBuffer_3);
     gl.bufferData( gl.ARRAY_BUFFER, flatten(normals_3), gl.STATIC_DRAW );
     // 获取着色器中vNormal变量，并向其传递数据
     vNormal_3 = gl.getAttribLocation( program, "vNormal" );
     gl.vertexAttribPointer( vNormal_3, 4, gl.FLOAT, false, 0, 0 );
     gl.enableVertexAttribArray( vNormal_3);
     // 创建缓冲区，并向缓冲区写入立方体的顶点信息
     vBuffer_3 = gl.createBuffer();
     gl.bindBuffer( gl.ARRAY_BUFFER, vBuffer_3 );
     gl.bufferData( gl.ARRAY_BUFFER, flatten(points_3), gl.STATIC_DRAW );
     // 获取着色器中vPosition变量，并向其传递数据
     vPosition_3 = gl.getAttribLocation( program, "vPosition" );
     gl.vertexAttribPointer(vPosition_3, 4, gl.FLOAT, false, 0, 0);
     gl.enableVertexAttribArray( vPosition_3 );
     // 创建缓冲区，并向缓冲区写入纹理的顶点信息
     tBuffer_3 = gl.createBuffer();
     gl.bindBuffer( gl.ARRAY_BUFFER, tBuffer_3);
     gl.bufferData( gl.ARRAY_BUFFER, flatten(texCoordsArray_3), gl.STATIC_DRAW);
     //获取着色器中vTexCoord变量，并向其传递数据
     vTexCoord_3 = gl.getAttribLocation( program, "vTexCoord");
     gl.vertexAttribPointer( vTexCoord_3, 2, gl.FLOAT, false, 0, 0);
     gl.enableVertexAttribArray(vTexCoord_3);

      // 创建缓冲区，并向缓冲区写入立方体每个面的法向量信息11111111111111111111111111111右脚
    nBuffer_4 = gl.createBuffer();
    gl.bindBuffer( gl.ARRAY_BUFFER, nBuffer_4);
    gl.bufferData( gl.ARRAY_BUFFER, flatten(normals_4), gl.STATIC_DRAW );
    // 获取着色器中vNormal变量，并向其传递数据
    vNormal_4 = gl.getAttribLocation( program, "vNormal" );
    gl.vertexAttribPointer( vNormal_4, 4, gl.FLOAT, false, 0, 0 );
    gl.enableVertexAttribArray( vNormal_4);
    // 创建缓冲区，并向缓冲区写入立方体的顶点信息
    vBuffer_4 = gl.createBuffer();
    gl.bindBuffer( gl.ARRAY_BUFFER, vBuffer_4 );
    gl.bufferData( gl.ARRAY_BUFFER, flatten(points_4), gl.STATIC_DRAW );
    // 获取着色器中vPosition变量，并向其传递数据
    vPosition_4 = gl.getAttribLocation( program, "vPosition" );
    gl.vertexAttribPointer(vPosition_4, 4, gl.FLOAT, false, 0, 0);
    gl.enableVertexAttribArray( vPosition_4 );
    // 创建缓冲区，并向缓冲区写入纹理的顶点信息
    tBuffer_4 = gl.createBuffer();
    gl.bindBuffer( gl.ARRAY_BUFFER, tBuffer_4);
    gl.bufferData( gl.ARRAY_BUFFER, flatten(texCoordsArray_4), gl.STATIC_DRAW);
    //获取着色器中vTexCoord变量，并向其传递数据
    vTexCoord_4 = gl.getAttribLocation( program, "vTexCoord");
    gl.vertexAttribPointer( vTexCoord_4, 2, gl.FLOAT, false, 0, 0);
    gl.enableVertexAttribArray(vTexCoord_4);

}

function timedCount()
{
    if(CubeTz1.toFixed(2) < 0.5 && CubeRotateAngle1==0){
        CubeTz1 = CubeTz1 + 0.02;
        //左手
        if(direct_1 == 0){
            CubeRotateAngleZ_1 = 0;
            CubeRotateAngleX_1 +=9;
        }else{
            CubeRotateAngleZ_1 = 0;
            CubeRotateAngleX_1 -=9;
        }
        if(CubeRotateAngleX_1 > 54){
            direct_1 = 1;
        }
        if(CubeRotateAngleX_1 < -54){
            direct_1 = 0;
        }
        //右手
        if(direct_2 == 0){
            CubeRotateAngleZ_2 = 0;
            CubeRotateAngleX_2 -=9;
        }else{
            CubeRotateAngleZ_2 = 0;
            CubeRotateAngleX_2 +=9;
        }
        if(CubeRotateAngleX_2 > 54){
            direct_2 = 0;
        }
        if(CubeRotateAngleX_2 < -54){
            direct_2 = 1;
        }
         //右腿
         if(direct_4 == 0){
            CubeRotateAngleZ_4 = 0;
            CubeRotateAngleX_4 +=2.5;
        }else{
            CubeRotateAngleZ_4 = 0;
            CubeRotateAngleX_4 -=2.5;
        }
        if(CubeRotateAngleX_4 > 15){
            direct_4 = 1;
        }
        if(CubeRotateAngleX_4 < -15){
            direct_4 = 0;
        }
        //左腿
        if(direct_3 == 0){
            CubeRotateAngleZ_3 = 0;
            CubeRotateAngleX_3 -=2.5;
        }else{
            CubeRotateAngleZ_3 = 0;
            CubeRotateAngleX_3 +=2.5;
        }
        if(CubeRotateAngleX_3 > 15){
            direct_3 = 0;
        }
        if(CubeRotateAngleX_3 < -15){
            direct_3 = 1;
        }
    }
    if(CubeTz1.toFixed(2) == 0.5 && CubeRotateAngle1==0){
        CubeRotateAngle1 = -90;
        CubeRotateAngleZ_1 = -CubeRotateAngleX_1;
        CubeRotateAngleZ_2 = -CubeRotateAngleX_2;
        CubeRotateAngleZ_3 = -CubeRotateAngleX_3;
        CubeRotateAngleZ_4 = -CubeRotateAngleX_4;
    }
    if(CubeTx1.toFixed(2) < 1 && CubeRotateAngle1==-90){
        CubeTx1 = CubeTx1 + 0.02;
        //左手
        if(direct_1 == 0){
            CubeRotateAngleX_1 = 0;
            CubeRotateAngleZ_1 -=9;
        }else{
            CubeRotateAngleX_1 = 0;
            CubeRotateAngleZ_1 +=9;
        }
        if(CubeRotateAngleZ_1 > 54){
            direct_1 = 0;
        }
        if(CubeRotateAngleZ_1 < -54){
            direct_1 = 1;
        }
        //右手
        if(direct_2 == 0){
            CubeRotateAngleX_2 = 0;
            CubeRotateAngleZ_2 +=9;
        }else{
            CubeRotateAngleX_2 = 0;
            CubeRotateAngleZ_2 -=9;
        }
        if(CubeRotateAngleZ_2 > 54){
            direct_2 = 1;
        }
        if(CubeRotateAngleZ_2 < -54){
            direct_2 = 0;
        }
        //右腿
        if(direct_4 == 0){
            CubeRotateAngleX_4 = 0;
            CubeRotateAngleZ_4 -=2.5;
        }else{
            CubeRotateAngleX_4 = 0;
            CubeRotateAngleZ_4 +=2.5;
        }
        if(CubeRotateAngleZ_4 > 15){
            direct_4 = 0;
        }
        if(CubeRotateAngleZ_4 < -15){
            direct_4 = 1;
        }
        //左腿
        if(direct_3 == 0){
            CubeRotateAngleX_3 = 0;
            CubeRotateAngleZ_3 +=2.5;
        }else{
            CubeRotateAngleX_3 = 0;
            CubeRotateAngleZ_3 -=2.5;
        }
        if(CubeRotateAngleZ_3 > 15){
            direct_3 = 1;
        }
        if(CubeRotateAngleZ_3 < -15){
            direct_3 = 0;
        }
    }
    if(CubeTx1.toFixed(2) == 1 && CubeRotateAngle1==-90){
        CubeRotateAngle1 = 180;
        CubeRotateAngleX_1 = -CubeRotateAngleZ_1;
        CubeRotateAngleX_2 = -CubeRotateAngleZ_2;
        CubeRotateAngleX_3 = -CubeRotateAngleZ_3;
        CubeRotateAngleX_4 = -CubeRotateAngleZ_4;
    }
    if(CubeTz1.toFixed(2) > -0.5 && CubeRotateAngle1==180){
        CubeTz1 = CubeTz1 - 0.02;
        //左手
        if(direct_1 == 0){
            CubeRotateAngleZ_1 = 0;
            CubeRotateAngleX_1 -=9;
        }else{
            CubeRotateAngleZ_1 = 0;
            CubeRotateAngleX_1 +=9;
        }
        if(CubeRotateAngleX_1 > 54){
            direct_1 = 0;
        }
        if(CubeRotateAngleX_1 < -54){
            direct_1 = 1;
        }
        //右手
        if(direct_2 == 0){
            CubeRotateAngleZ_2 = 0;
            CubeRotateAngleX_2 +=9;
        }else{
            CubeRotateAngleZ_2 = 0;
            CubeRotateAngleX_2 -=9;
        }
        if(CubeRotateAngleX_2 > 54){
            direct_2 = 1;
        }
        if(CubeRotateAngleX_2 < -54){
            direct_2 = 0;
        }
        //右腿
        if(direct_4 == 0){
            CubeRotateAngleZ_4 = 0;
            CubeRotateAngleX_4 -=2.5;
        }else{
            CubeRotateAngleZ_4 = 0;
            CubeRotateAngleX_4 +=2.5;
        }
        if(CubeRotateAngleX_4 > 15){
            direct_4 = 0;
        }
        if(CubeRotateAngleX_4 < -15){
            direct_4 = 1;
        }
        //左腿
        if(direct_3 == 0){
            CubeRotateAngleZ_3 = 0;
            CubeRotateAngleX_3 +=2.5;
        }else{
            CubeRotateAngleZ_3 = 0;
            CubeRotateAngleX_3 -=2.5;
        }
        if(CubeRotateAngleX_3 > 15){
            direct_3 = 1;
        }
        if(CubeRotateAngleX_3 < -15){
            direct_3 = 0;
        }
    }
    if(CubeTz1.toFixed(2) == -0.5 && CubeRotateAngle1==180){
        CubeRotateAngle1=90;
        CubeRotateAngleZ_1 = -CubeRotateAngleX_1;
        CubeRotateAngleZ_2 = -CubeRotateAngleX_2;
        CubeRotateAngleZ_3 = -CubeRotateAngleX_3;
        CubeRotateAngleZ_4 = -CubeRotateAngleX_4;
    }
    if(CubeTx1.toFixed(2) > -0.2 && CubeRotateAngle1==90){
        CubeTx1 = CubeTx1 - 0.02;
        //左手
        if(direct_1 == 0){
            CubeRotateAngleX_1 = 0;
            CubeRotateAngleZ_1 +=9;
        }else{
            CubeRotateAngleX_1 = 0;
            CubeRotateAngleZ_1 -=9;
        }
        if(CubeRotateAngleZ_1 > 54){
            direct_1 = 1;
        }
        if(CubeRotateAngleZ_1 < -54){
            direct_1 = 0;
        }
        //右手
        if(direct_2 == 0){
            CubeRotateAngleX_2 = 0;
            CubeRotateAngleZ_2 -=9;
        }else{
            CubeRotateAngleX_2 = 0;
            CubeRotateAngleZ_2 +=9;
        }
        if(CubeRotateAngleZ_2 > 54){
            direct_2 = 0;
        }
        if(CubeRotateAngleZ_2 < -54){
            direct_2 = 1;
        }
        //右腿
        if(direct_4 == 0){
            CubeRotateAngleX_4 = 0;
            CubeRotateAngleZ_4 +=2.5;
        }else{
            CubeRotateAngleX_4 = 0;
            CubeRotateAngleZ_4 -=2.5;
        }
        if(CubeRotateAngleZ_4 > 15){
            direct_4 = 1;
        }
        if(CubeRotateAngleZ_4 < -15){
            direct_4 = 0;
        }
        //左腿
        if(direct_3 == 0){
            CubeRotateAngleX_3 = 0;
            CubeRotateAngleZ_3 -=2.5;
        }else{
            CubeRotateAngleX_3 = 0;
            CubeRotateAngleZ_3 +=2.5;
        }
        if(CubeRotateAngleZ_3 > 15){
            direct_3 = 0;
        }
        if(CubeRotateAngleZ_3 < -15){
            direct_3 = 1;
        }
    }
    if(CubeTx1.toFixed(2) == -0.2 && CubeRotateAngle1==90){
        CubeRotateAngle1=0;
        CubeRotateAngleX_1 = CubeRotateAngleZ_1;
        CubeRotateAngleX_2 = CubeRotateAngleZ_2;
        CubeRotateAngleX_3 = CubeRotateAngleZ_3;
        CubeRotateAngleX_4 = CubeRotateAngleZ_4;
    }
    t=setTimeout("timedCount()",100)
}

function bodyMove(){
    // 左手臂变换
    var init = translate(-0.3, -0.15, 0); // 初始变换矩阵，用于设置模型的初始位置
    var S = scalem(scalePercent1, scalePercent1, scalePercent1);
    var T = translate(CubeTx1, CubeTy1, CubeTz1);
    var R = rotateY(CubeRotateAngle1);
    var Rx_1 = rotateX(CubeRotateAngleX_1);
    var Rz_1 = rotateZ(CubeRotateAngleZ_1);
    
    modelViewMatrix = mult(mult(mult(init, T), mult(Rz_1,mult(Rx_1,R))), S);
    var m = mult(mult(T, R), S); // 用于处理正面的方向
    
    // 记录正面的方向
    direct1 = vec4( 0.0, 0.0, 1.0, 1.0 ); // 初始化初始方向
    direct1 = multMat4Vec4(m, direct1);
    
    gl.uniformMatrix4fv(modelViewMatrixLoc, false, flatten(modelViewMatrix));
    
    normalMatrix = modelViewMatrix;
    gl.uniformMatrix4fv(normalMatrixLoc, false, flatten(normalMatrix));
    
    // 顶点
    gl.bindBuffer(gl.ARRAY_BUFFER, vBuffer_1);
    gl.vertexAttribPointer(vPosition1, 4, gl.FLOAT, false, 0, 0);
    
    // 设置材质
    materialAmbient = vec4( 1.0, 1.0, 0.5, 1.0 );
    materialDiffuse = vec4( 1.0, 0.8, 0.0, 1.0);
    materialSpecular = vec4( 1.0, 1.0, 1.0, 1.0 );
    materialShininess = 100.0;
    var ambientProduct = mult(lightAmbient, materialAmbient);
    var diffuseProduct = mult(lightDiffuse, materialDiffuse);
    var specularProduct = mult(lightSpecular, materialSpecular);
    gl.uniform4fv( gl.getUniformLocation(program,
        "ambientProduct"),flatten(ambientProduct) );
    gl.uniform4fv( gl.getUniformLocation(program,
        "diffuseProduct"),flatten(diffuseProduct) );
    gl.uniform4fv( gl.getUniformLocation(program,
        "specularProduct"),flatten(specularProduct) );
    gl.uniform4fv( gl.getUniformLocation(program,
        "lightPosition"),flatten(lightPosition) );
    gl.uniform1f( gl.getUniformLocation(program,
        "shininess"),materialShininess );

    gl.bindBuffer( gl.ARRAY_BUFFER, tBuffer_1);
    gl.vertexAttribPointer( vTexCoord_1, 2, gl.FLOAT, false, 0, 0);
    gl.uniform1i(gl.getUniformLocation(program, "bTexCoord"), 1);
    gl.activeTexture(gl.TEXTURE1);
    gl.enableVertexAttribArray(vTexCoord1);
    
    gl.drawArrays(gl.TRIANGLES, 0, 36);


    // 右手臂变换
    var init = translate(-0.3, -0.15, 0); // 初始变换矩阵，用于设置模型的初始位置
    var S = scalem(scalePercent1, scalePercent1, scalePercent1);
    var T = translate(CubeTx1, CubeTy1, CubeTz1);
    var R = rotateY(CubeRotateAngle1);
    var Rx_2 = rotateX(CubeRotateAngleX_2);
    var Rz_2 = rotateZ(CubeRotateAngleZ_2);
    
    modelViewMatrix = mult(mult(mult(init, T), mult(Rz_2,mult(Rx_2,R))), S);
    var m = mult(mult(T, R), S); // 用于处理正面的方向
    
    // 记录正面的方向
    direct1 = vec4( 0.0, 0.0, 1.0, 1.0 ); // 初始化初始方向
    direct1 = multMat4Vec4(m, direct1);
    
    gl.uniformMatrix4fv(modelViewMatrixLoc, false, flatten(modelViewMatrix));
    
    normalMatrix = modelViewMatrix;
    gl.uniformMatrix4fv(normalMatrixLoc, false, flatten(normalMatrix));
    
    // 顶点
    gl.bindBuffer(gl.ARRAY_BUFFER, vBuffer_2);
    gl.vertexAttribPointer(vPosition1, 4, gl.FLOAT, false, 0, 0);
    
    // 设置材质
    materialAmbient = vec4( 1.0, 1.0, 0.5, 1.0 );
    materialDiffuse = vec4( 1.0, 0.8, 0.0, 1.0);
    materialSpecular = vec4( 1.0, 1.0, 1.0, 1.0 );
    materialShininess = 100.0;
    var ambientProduct = mult(lightAmbient, materialAmbient);
    var diffuseProduct = mult(lightDiffuse, materialDiffuse);
    var specularProduct = mult(lightSpecular, materialSpecular);
    gl.uniform4fv( gl.getUniformLocation(program,
        "ambientProduct"),flatten(ambientProduct) );
    gl.uniform4fv( gl.getUniformLocation(program,
        "diffuseProduct"),flatten(diffuseProduct) );
    gl.uniform4fv( gl.getUniformLocation(program,
        "specularProduct"),flatten(specularProduct) );
    gl.uniform4fv( gl.getUniformLocation(program,
        "lightPosition"),flatten(lightPosition) );
    gl.uniform1f( gl.getUniformLocation(program,
        "shininess"),materialShininess );

    gl.bindBuffer( gl.ARRAY_BUFFER, tBuffer_2);
    gl.vertexAttribPointer( vTexCoord_2, 2, gl.FLOAT, false, 0, 0);
    gl.uniform1i(gl.getUniformLocation(program, "bTexCoord"), 1);
    gl.activeTexture(gl.TEXTURE1);
    gl.enableVertexAttribArray(vTexCoord1);
    
    gl.drawArrays(gl.TRIANGLES, 0, 36);

    // 左腿变换
    var init = translate(-0.3, -0.15, 0); // 初始变换矩阵，用于设置模型的初始位置
    var S = scalem(scalePercent1, scalePercent1, scalePercent1);
    var T = translate(CubeTx1, CubeTy1, CubeTz1);
    var R = rotateY(CubeRotateAngle1);
    var Rx_3 = rotateX(CubeRotateAngleX_3);
    var Rz_3 = rotateZ(CubeRotateAngleZ_3);
    
    modelViewMatrix = mult(mult(mult(init, T), mult(Rz_3,mult(Rx_3,R))), S);
    var m = mult(mult(T, R), S); // 用于处理正面的方向
    
    // 记录正面的方向
    direct1 = vec4( 0.0, 0.0, 1.0, 1.0 ); // 初始化初始方向
    direct1 = multMat4Vec4(m, direct1);
    
    gl.uniformMatrix4fv(modelViewMatrixLoc, false, flatten(modelViewMatrix));
    
    normalMatrix = modelViewMatrix;
    gl.uniformMatrix4fv(normalMatrixLoc, false, flatten(normalMatrix));
    
    // 顶点
    gl.bindBuffer(gl.ARRAY_BUFFER, vBuffer_3);
    gl.vertexAttribPointer(vPosition1, 4, gl.FLOAT, false, 0, 0);
    
    // 设置材质
    materialAmbient = vec4( 1.0, 1.0, 0.5, 1.0 );
    materialDiffuse = vec4( 1.0, 0.8, 0.0, 1.0);
    materialSpecular = vec4( 1.0, 1.0, 1.0, 1.0 );
    materialShininess = 100.0;
    var ambientProduct = mult(lightAmbient, materialAmbient);
    var diffuseProduct = mult(lightDiffuse, materialDiffuse);
    var specularProduct = mult(lightSpecular, materialSpecular);
    gl.uniform4fv( gl.getUniformLocation(program,
        "ambientProduct"),flatten(ambientProduct) );
    gl.uniform4fv( gl.getUniformLocation(program,
        "diffuseProduct"),flatten(diffuseProduct) );
    gl.uniform4fv( gl.getUniformLocation(program,
        "specularProduct"),flatten(specularProduct) );
    gl.uniform4fv( gl.getUniformLocation(program,
        "lightPosition"),flatten(lightPosition) );
    gl.uniform1f( gl.getUniformLocation(program,
        "shininess"),materialShininess );

    gl.bindBuffer( gl.ARRAY_BUFFER, tBuffer_3);
    gl.vertexAttribPointer( vTexCoord_3, 2, gl.FLOAT, false, 0, 0);
    gl.uniform1i(gl.getUniformLocation(program, "bTexCoord"), 1);
    gl.activeTexture(gl.TEXTURE1);
    gl.enableVertexAttribArray(vTexCoord1);
    
    gl.drawArrays(gl.TRIANGLES, 0, 36*2);

    // 右腿变换
    var init = translate(-0.3, -0.15, 0); // 初始变换矩阵，用于设置模型的初始位置
    var S = scalem(scalePercent1, scalePercent1, scalePercent1);
    var T = translate(CubeTx1, CubeTy1, CubeTz1);
    var R = rotateY(CubeRotateAngle1);
    var Rx_4 = rotateX(CubeRotateAngleX_4);
    var Rz_4 = rotateZ(CubeRotateAngleZ_4);
    
    modelViewMatrix = mult(mult(mult(init, T), mult(Rz_4,mult(Rx_4,R))), S);
    var m = mult(mult(T, R), S); // 用于处理正面的方向
    
    // 记录正面的方向
    direct1 = vec4( 0.0, 0.0, 1.0, 1.0 ); // 初始化初始方向
    direct1 = multMat4Vec4(m, direct1);
    
    gl.uniformMatrix4fv(modelViewMatrixLoc, false, flatten(modelViewMatrix));
    
    normalMatrix = modelViewMatrix;
    gl.uniformMatrix4fv(normalMatrixLoc, false, flatten(normalMatrix));
    
    // 顶点
    gl.bindBuffer(gl.ARRAY_BUFFER, vBuffer_4);
    gl.vertexAttribPointer(vPosition1, 4, gl.FLOAT, false, 0, 0);
    
    // 设置材质
    materialAmbient = vec4( 1.0, 1.0, 0.5, 1.0 );
    materialDiffuse = vec4( 1.0, 0.8, 0.0, 1.0);
    materialSpecular = vec4( 1.0, 1.0, 1.0, 1.0 );
    materialShininess = 100.0;
    var ambientProduct = mult(lightAmbient, materialAmbient);
    var diffuseProduct = mult(lightDiffuse, materialDiffuse);
    var specularProduct = mult(lightSpecular, materialSpecular);
    gl.uniform4fv( gl.getUniformLocation(program,
        "ambientProduct"),flatten(ambientProduct) );
    gl.uniform4fv( gl.getUniformLocation(program,
        "diffuseProduct"),flatten(diffuseProduct) );
    gl.uniform4fv( gl.getUniformLocation(program,
        "specularProduct"),flatten(specularProduct) );
    gl.uniform4fv( gl.getUniformLocation(program,
        "lightPosition"),flatten(lightPosition) );
    gl.uniform1f( gl.getUniformLocation(program,
        "shininess"),materialShininess );

    gl.bindBuffer( gl.ARRAY_BUFFER, tBuffer_4);
    gl.vertexAttribPointer( vTexCoord_4, 2, gl.FLOAT, false, 0, 0);
    gl.uniform1i(gl.getUniformLocation(program, "bTexCoord"), 1);
    gl.activeTexture(gl.TEXTURE1);
    gl.enableVertexAttribArray(vTexCoord1);
    
    gl.drawArrays(gl.TRIANGLES, 0, 36*2);
}
