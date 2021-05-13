define("pages/voice_component.js",["biz_wap/zepto/zepto.js","biz_common/dom/event.js","biz_common/tmpl.js","pages/music_player.js","pages/player_adaptor.js","biz_common/dom/class.js","pages/report.js","pages/music_report_conf.js","pages/player_tips.js","biz_wap/jsapi/leaveReport.js","biz_wap/utils/mmversion.js","biz_wap/utils/ajax.js","biz_wap/utils/openUrl.js","pages/qqmusic_ctrl.js","pages/kugoumusic_ctrl.js","album/utils/report.js"],function(e){
"use strict";
function t(){
C.hasInit||(i(),n(),p(),C.hasInit=!0);
}
function a(e){
t(),this._o={
protocal:"",
wxIndex:0,
type:0,
comment_id:"",
src:"",
jsapi2Src:"",
mid:"",
songId:"",
otherid:"",
albumid:"",
jumpurlkey:"",
autoPlay:!1,
duration:0,
needVioceMutex:!0,
appPlay:!0,
title:"",
allowPause:!1,
singer:"",
epname:"",
coverImgUrl:"",
webUrl:[location.protocol,"//mp.weixin.qq.com/s?referFrom=#referFrom#&songid=#songId#&__biz=",window.biz,"&mid=",window.mid,"&idx=",window.idx,"&sn=",window.sn,"#wechat_redirect"].join(""),
musicbar_url:"",
playingCss:"",
pauseCss:"",
playCssDom:"",
playArea:"",
progress:"",
detailUrl:"",
detailArea:"",
fileSize:0,
playtimeDom:"",
loadingDom:"",
bufferDom:"",
playdotDom:"",
seekRange:"",
seekContainer:""
},this._init(e),C.allComponent.push(this);
}
function o(e){
if(!e.isReport){
var t=(e.getAttribute("data-link"),$(e).parent().parent().siblings()),a=$(e).data("album"),o=t.attr("voice_encode_fileid"),r=$(e).data("title");
e.isReport=1,P.cardReport({
albumId:a,
albumType:7,
eventType:1,
audioid:o,
title:r
});
}
}
function r(e,t,a,o){
C.num++,t.musicSupport=C.musicSupport,t.show_not_support=!1,C.musicSupport||1!=C.num||(t.show_not_support=!0);
var r=document.createElement("div"),n="";
if(n=m.tmpl(e,t,!1),r.innerHTML=n,o===!0)a.appendChild(r.children[0]);else{
var i=a.parentNode;
if(!i)return;
i.lastChild===a?i.appendChild(r.children[0]):i.insertBefore(r.children[0],a.nextSibling);
}
}
function n(){
C.hasInit||h.inQMClient&&s("QMClient_pv",1);
}
function i(){
window.reportMid=[],window.reportVoiceid=[];
for(var e in w)if(w.hasOwnProperty(e)){
var t=w[e],a=t.split("_");
C.reportData2[e]={
id:a[0],
key:a[1],
count:0
};
}
}
function s(e,t){
C.reportData2[e]&&(t=t||1,C.reportData2[e].count+=t,C.debug&&console.log("addpv:"+e+" count:"+C.reportData2[e].count));
}
function p(){
I.gtVersion("7.0.6")||y.on(window,"unload",function(){
for(var e=l(),t=JSON.parse(e.report_list),a=0;a<t.length;a++)x({
type:"POST",
url:"/mp/musicreport?#wechat_redirect",
timeout:2e4,
async:!0,
data:t[a]
});
}),C.repotIntervalId&&clearInterval(C.repotIntervalId),C.repotIntervalId=setInterval(function(){
c();
},3e4);
}
function l(){
f.triggerUnloadPlaying(),c();
for(var e,t={},a=0,o=C.allComponent.length;o>a;a++){
var r=C.allComponent[a];
r.player&&"function"==typeof r.player.getPlayTotalTime&&(C.reportData[r._o.type].play_last_time[r._g.posIndex]=parseInt(1e3*r.player.getPlayTotalTime())),
"number"!=typeof r._status||1!==r._status&&4!==r._status||(e=r._o.songId);
}
e&&(t.current_musicid=e);
var n=[];
for(var a in C.reportData)n=n.concat(D.musicreport({
data:C.reportData[a]
}));
t.report_list=JSON.stringify(n),i();
for(var a=0,o=C.allComponent.length;o>a;a++){
var r=C.allComponent[a];
r&&"function"==typeof r._initReportData&&r._initReportData(),r.player&&"function"==typeof r.player.resetPlayTotalTime&&r.player.resetPlayTotalTime();
}
return t;
}
function c(){
var e=[];
for(var t in C.reportData2)if(C.reportData2.hasOwnProperty(t)){
var a=C.reportData2[t];
a.count>0&&(e.push(a.id+"_"+a.key+"_"+a.count),a.count=0);
}
e.length>0&&x({
type:"POST",
url:"/mp/jsmonitor?#wechat_redirect",
timeout:2e4,
async:!1,
data:{
idkey:e.join(";"),
t:Math.random()
}
});
}
function d(e){
return new a(e);
}
function u(e){
if(isNaN(e))return"00:00";
e=Math.floor(e);
var t=Math.floor(e/3600),a=Math.floor((e-3600*t)/60),o=e-3600*t-60*a;
return 0!=t?(10>t&&(t="0"+t),t+=":"):t="",10>a&&(a="0"+a),10>o&&(o="0"+o),t+a+":"+o;
}
function _(e){
return e=(e||"").replace(/&#96;/g,"`").replace(/&#61;/g,"=").replace(/&#39;/g,"'").replace(/&quot;/g,'"').replace(/&lt;/g,"<").replace(/&gt;/g,">").replace(/&amp;/g,"&");
}
function g(e){
return e=(e||"").replace(/&/g,"&amp;").replace(/>/g,"&gt;").replace(/</g,"&lt;").replace(/"/g,"&quot;").replace(/'/g,"&#39;").replace(/=/g,"&#61;").replace(/`/g,"&#96;");
}
e("biz_wap/zepto/zepto.js");
var y=e("biz_common/dom/event.js"),m=e("biz_common/tmpl.js"),f=e("pages/music_player.js"),h=e("pages/player_adaptor.js"),v=e("biz_common/dom/class.js"),D=e("pages/report.js"),w=e("pages/music_report_conf.js"),k=e("pages/player_tips.js"),b=e("biz_wap/jsapi/leaveReport.js"),I=e("biz_wap/utils/mmversion.js"),x=e("biz_wap/utils/ajax.js"),j=e("biz_wap/utils/openUrl.js").openUrlWithExtraWebview,C={
allComponent:[],
hasInit:!1,
reportId:"28306",
musicSupport:f.getSurportType(),
debug:location.href.indexOf("vconsole=1")>0||document.cookie&&document.cookie.indexOf("vconsole_open=1")>-1?!0:!1,
reportData:{},
posIndex:{},
num:0,
reportData2:{},
adapter:{
m:e("pages/qqmusic_ctrl.js"),
k:e("pages/kugoumusic_ctrl.js")
},
needReport11982:!1,
repotIntervalId:null
},P=e("album/utils/report.js"),S=null;
return"function"==typeof IntersectionObserver&&(S=new IntersectionObserver(function(e){
e.forEach(function(e){
e.isIntersecting&&o(e.target);
});
})),a.prototype._init=function(e){
this._extend(e),this._g={
posIndex:void 0,
tag:"",
canDragBar:!1,
barDraging:!1,
canGoDetail:!0
},5==this._o.type||6==this._o.type||9==this._o.type?this._g.tag="k":this._o.type>=2&&this._o.type<=4?this._g.tag="v":7==this._o.type?this._g.tag="a":(0==this._o.type||1==this._o.type||8==this._o.type)&&(this._g.tag="m"),
this._initData(),this._initQQmusicLyric(),this._initReportData(),this._initPlayer();
},a.prototype._initData=function(){},a.prototype._initQQmusicLyric=function(){
var e=this._o,t=this._g;
e.webUrl="m"==t.tag?e.webUrl.replace("#songId#",e.songId||"").replace("#referFrom#","music.qq.com"):e.webUrl.replace("#songId#","").replace("#referFrom#","");
},a.prototype._initReportData=function(){
var e=this._o,t=this._g;
"v"==t.tag?window.reportVoiceid.push(e.songId):"m"==t.tag&&window.reportMid.push(e.songId),
"undefined"==typeof C.reportData[e.type]&&(C.reportData[e.type]=D.getMusicReportData(e),
C.posIndex[e.type]=0),"undefined"==typeof t.posIndex&&(t.posIndex=C.posIndex[e.type]++);
var a=C.reportData[e.type];
a.musicid[t.posIndex]=e.songId,a.commentid[t.posIndex]=e.comment_id,a.hasended[t.posIndex]=0,
a.mtitle[t.posIndex]=e.title,a.detail_click[t.posIndex]=0,a.duration2[t.posIndex]=parseInt(1e3*e.duration),
a.errorcode[t.posIndex]=0,a.play_duration2[t.posIndex]=0,a.seek[t.posIndex]=0,a.seek_position[t.posIndex]=[],
a.play_last_time[t.posIndex]=0,a.local_time[t.posIndex]=0,a.seek_loaded[t.posIndex]=[];
},a.prototype._initPlayer=function(){
if(C.musicSupport){
var e=this,t=this._o,a=this._g.tag;
t.onStatusChange=this._statusChangeCallBack(),t.onTimeupdate=this._timeupdateCallBack(),
t.onError=this._errorCallBack(),t.onUpdateSeekRange=this._onUpdateSeekRange(),t.onAndroidForceH5=function(){
s("force_h5",1);
},t.onH5Begin2Play=function(){
s(a+"_pv",1),s(a+"_h5_pv",1);
},t.onH5Error=function(t,o){
s(a+"_h5_err_total",1),s(a+"_h5_err_"+o.code,1),e._reportH5Error({
type:1,
code:o.code
});
},t.onJsapi1Begin2Play=function(){
s(a+"_pv",1),s(a+"_wx_pv",1),s(a+"_wx_pv_1",1);
},t.onJsapi2Begin2Play=function(e,o){
s(a+"_pv",1),s(a+"_wx_pv",1),s(a+"_wx_pv_2",1),t.jsapi2Src&&t.jsapi2Src!=t.src&&s("aac_pv",1),
t.musicPlayerOnJsapi2Begin2Play&&t.musicPlayerOnJsapi2Begin2Play(o);
},t.onJsapi2PlaySuccess=function(e,a){
t.musicPlayerOnJsapi2PlaySuccess&&t.musicPlayerOnJsapi2PlaySuccess(a);
},t.onJsapi2Begin2PlayErr=function(){
if(s(a+"_wx_err_1",1),t.jsapi2Src&&t.jsapi2Src!=t.src){
var e="acc_start_error;type:#type#;uin:"+(window.user_uin||"")+";playurl:"+t.jsapi2Src+";pageurl:"+location.href;
f.isAndroid?(D.logReport("",e.replace("#type#","android"),"ajax"),s("android_aac_err_1",1)):(D.logReport("",e.replace("#type#","ios"),"ajax"),
s("ios_aac_err_1",1));
}
},t.onJsapi2PlayingErr=function(){
if(s(a+"_wx_err_2",1),t.jsapi2Src&&t.jsapi2Src!=t.src){
var e="acc_ing_error;type:#type#;uin:"+(window.user_uin||"")+";playurl:"+t.jsapi2Src+";pageurl:"+location.href;
f.isAndroid?(D.logReport("",e.replace("#type#","android"),"ajax"),s("android_aac_err_2",1)):(D.logReport("",e.replace("#type#","ios"),"ajax"),
s("ios_aac_err_2",1));
}
},t.onJsapi2PlayingStop=function(){
var e=a+"_stoped_";
e+=f.isAndroid?"android":"ios",s(e,1);
},t.onJsapi2PlayingPause=function(){
var e=a+"_paused_";
e+=f.isAndroid?"android":"ios",s(e,1);
},t.onSeekErr=function(){
if(s(a+"_seek_err",1),t.jsapi2Src&&t.jsapi2Src!=t.src){
var e="acc_seek_error;type:#type#;uin:"+(window.user_uin||"")+";playurl:"+t.jsapi2Src+";pageurl:"+location.href;
f.isAndroid?(D.logReport("",e.replace("#type#","android"),"ajax"),s("android_aac_err_3",1)):(D.logReport("",e.replace("#type#","ios"),"ajax"),
s("ios_aac_err_3",1));
}
},t.onUnloadPlaying=function(){
s(a+"_unload_wx_pv",1);
},t.onQMClientPlay=function(){
s("QMClient_play",1);
},t.onSeekNeed2Load=function(){
if(e.player&&e.player.surportSeekRange()&&t.playdotDom){
var a=C.reportData[e._o.type],o=a.seek_position[e._g.posIndex].length;
o>0&&(a.seek_loaded[e._g.posIndex][o-1]=1);
}
},t.onSeekNotNeed2Load=function(){
if(e.player&&e.player.surportSeekRange()&&t.playdotDom){
var a=C.reportData[e._o.type],o=a.seek_position[e._g.posIndex].length;
o>0&&(a.seek_loaded[e._g.posIndex][o-1]=0);
}
},h.create(this._o,{
callback:function(t){
e.player=t,e.afterCreatePlayer();
}
});
}
},a.prototype.afterCreatePlayer=function(){
this._playEvent();
},a.prototype.isInSeekrang=function(e){
var t=this._o.seekRange;
if(!t)return!1;
if(t===e)return!0;
for(var a=t.getElementsByTagName("*"),o=0,r=a.length;r>o;o++)if(a[o]===e)return!0;
return!1;
},a.prototype._playEvent=function(){
var e=this,t=this._o,a=this._g;
if(t.detailUrl&&t.detailArea&&y.on(t.detailArea,"click",function(o){
if(!a.barDraging&&a.canGoDetail){
var r=o.target||o.srcElement;
r&&e.isInSeekrang(r)||("v"==a.tag?(C.reportData[t.type].detail_click[a.posIndex]=1,
window.__second_open__?j(t.detailUrl):window.location.href=t.detailUrl):("m"==a.tag||"k"==a.tag)&&C.adapter[a.tag].getPlayUrl(t,{
callback:function(e){
e.canplay?(C.reportData[t.type].detail_click[a.posIndex]=1,window.__second_open__?j(t.detailUrl):window.location.href=t.detailUrl):e.msg&&new k({
msg:e.msg
});
}
}));
}
}),t.albumDom&&(S&&S.observe(t.albumDom),y.on(t.albumDom,"click",function(){
var e=t.albumDom.getAttribute("data-link").replace("#wechat_redirect","&scene=173#wechat_redirect"),a=$(t.albumDom).parent().parent().siblings(),o=$(t.albumDom).data("album"),r=a.attr("voice_encode_fileid"),n=$(t.albumDom).data("title");
return P.cardReport({
albumId:o,
albumType:7,
eventType:2,
audioid:r,
title:n
}),j(e),!1;
},!0)),C.musicSupport){
var o=0,r=4,n=5;
switch(1*t.type){
case 0:
o=1;
break;

case 1:
o=13;
break;

case 8:
o=14;
break;

case 2:
o=3;
break;

case 3:
o=6;
break;

case 4:
o=7;
break;

case 5:
o=10;
break;

case 6:
o=15;
break;

case 7:
o=11;
break;

case 9:
o=12;
}
var i="";
i=t.allowPause?t.pauseCss||t.playingCss:t.playingCss,y.tap(t.playArea,function(){
return console.log("click playArea",v.hasClass(t.playCssDom,i)),v.hasClass(t.playCssDom,i)?(t.allowPause?e.player.pause():e.player.stop(),
D.report({
type:o,
comment_id:t.comment_id,
voiceid:t.songId,
action:n
})):"v"==a.tag||"a"==a.tag?e._playMusic(o,r):C.adapter[a.tag].getPlayUrl(t,{
callback:function(n){
n.canplay&&n.play_url?(n.duration&&(t.duration=n.duration,e.player.setDuration(t.duration),
C.reportData[t.type].duration2[a.posIndex]=parseInt(1e3*t.duration)),e.player.setSrc(n.play_url),
8!=n.status||n.in_cache?e._playMusic(o,r):new k({
msg:"该音乐为付费音乐，当前为你播放试听片段",
onClick:function(){
e._playMusic(o,r);
}
})):n.msg&&new k({
msg:n.msg
});
}
}),!1;
}),e._dragEvent();
}
},a.prototype.getSeekRangeOffsetLeft=function(){
var e=0,t=this._o.seekRange,a=!1,o=window.__zoom||1;
for(1!=o&&(a=!0);t&&t!=document.body;)e+=a?t.offsetLeft*o:t.offsetLeft,"page-content"==t.id&&(a=!1),
t=t.offsetParent;
return e;
},a.prototype._dragEvent=function(){
var e=this,t=this._o,a=this._g,o=t.seekRange;
if(o){
var r=e.player.getDuration();
a.seekData={
zoom:window.__zoom||1,
duration:r,
startTime:0,
dragTime:0,
downX:0,
moveX:0
},y.on(o,"mousedown",function(t){
a.canDragBar&&(e._pointerDownHandler({
x:t.pageX||t.clientX
}),t.preventDefault());
}),y.on(t.seekContainer,"mousemove",function(t){
a.canDragBar&&a.barDraging&&(e._pointerMoveHandler({
x:t.pageX||t.clientX
}),t.preventDefault(),t.stopPropagation());
}),y.on(document.body,"mouseup",function(t){
return a.canDragBar&&a.barDraging?(e._pointerUpHandler({
x:t.pageX||t.clientX
}),t.preventDefault(),t.stopPropagation(),!1):void 0;
}),y.on(o,"touchstart",function(t){
a.canDragBar&&(e._pointerDownHandler({
x:t.changedTouches[0].clientX
}),t.preventDefault());
}),y.on(o,"touchmove",function(t){
a.canDragBar&&a.barDraging&&(e._pointerMoveHandler({
x:t.changedTouches[0].clientX
}),t.preventDefault(),t.stopPropagation());
}),y.on(o,"touchend",function(t){
return a.canDragBar&&a.barDraging?(e._pointerUpHandler({
x:t.changedTouches[0].clientX
}),t.preventDefault(),t.stopPropagation(),!1):void 0;
});
}
},a.prototype._pointerDownHandler=function(e){
var t=this._g;
t.barDraging=!0,t.canGoDetail=!1,t.seekData.downX=e.x,t.seekData.startTime=this.player.getCurTime();
},a.prototype._pointerMoveHandler=function(e){
var t=this._g,a=t.seekData;
a.moveX=e.x;
var o=this.getSeekRangeOffsetLeft(),r=(a.moveX-o)/a.zoom/this._o.seekRange.offsetWidth;
r=Math.min(r,1),r=Math.max(r,0),a.dragTime=r*a.duration,a.dragTime!=a.startTime&&this._updateProgressBar(a.dragTime);
},a.prototype._pointerUpHandler=function(e){
var t=this._g,a=t.seekData;
a.dragTime||this._pointerMoveHandler({
x:e.x
}),t.barDraging=!1,this.player.seek(a.dragTime),C.reportData[this._o.type].seek[t.posIndex]=1,
C.reportData[this._o.type].seek_position[t.posIndex].push(parseInt(1e3*a.startTime)+","+parseInt(1e3*a.dragTime));
var o=C.reportData[this._o.type].seek_position[t.posIndex].length;
C.reportData[this._o.type].seek_loaded[t.posIndex][o-1]=0,t.seekData.startTime=0,
t.seekData.dragTime=0,t.seekData.downX=0,t.seekData.moveX=0,setTimeout(function(){
t.canGoDetail=!0;
},1e3);
},a.prototype._playMusic=function(e,t){
var a=this._o,o=this._g;
this.player.play(),C.reportData[a.type].hasended[o.posIndex]=1,0==C.reportData[a.type].local_time[o.posIndex]&&(C.reportData[a.type].local_time[o.posIndex]=parseInt(+new Date/1e3)),
D.report({
type:e,
comment_id:a.comment_id,
voiceid:a.songId,
action:t
}),I.gtVersion("7.0.6")&&!C.needReport11982&&(C.needReport11982=!0,b.addSpecificReport("music_data",l),
console.log("music play leave report added"));
},a.prototype._extend=function(e){
for(var t in e)this._o[t]=e[t];
},a.prototype._onUpdateSeekRange=function(){
var e=this,t=e._o,a=e._g;
return function(e){
this.surportSeekRange()&&t.bufferDom&&t.playdotDom?(a.canDragBar=!0,t.playdotDom.style.display="block",
t.bufferDom.style.width=1*e+"%"):(a.canDragBar=!1,t.playdotDom&&(t.playdotDom.style.display="none"));
};
},a.prototype._statusChangeCallBack=function(){
var e=this;
return function(t,a){
e._status=a,e._updatePlayerCss(this,a),e._o.musicPlayerStatusChange&&e._o.musicPlayerStatusChange(a);
};
},a.prototype._timeupdateCallBack=function(){
var e=this,t=this._o,a=this._g;
return function(o,r){
e._updateProgress(r),0!=r&&(C.reportData[t.type].play_duration2[a.posIndex]=parseInt(1e3*r)),
e._o.timeupdateCallBack&&e._o.timeupdateCallBack(r);
};
},a.prototype._errorCallBack=function(){
var e=this,t=this._o,a=this._g;
return function(o,r){
C.reportData[t.type].errorcode[a.posIndex]=r.code,e._updatePlayerCss(this,3);
};
},a.prototype._reportH5Error=function(e){
if("mp.weixin.qq.com"==location.host&&1==e.type||C.debug){
var t=["code:",e.code,";type:",this._o.type,";url:",window.location.href];
this.player&&t.push(";src:"+this.player.getSrc());
var a=new Image;
a.src=["https://badjs.weixinbridge.com/badjs?level=4&id=112&msg=",encodeURIComponent(t.join("")),"&uin=",window.uin||"","&from=",this._o.type].join("");
}
},a.prototype._updatePlayerCss=function(e,t){
!!C.debug&&console.log("status:"+t);
{
var a=this._o,o=a.playCssDom;
a.progress;
}
2==t?(v.removeClass(o,a.playingCss),a.pauseCss&&v.removeClass(o,a.pauseCss),a.playdotDom&&(e.surportSeekRange()?(a.playdotDom.style.display="block",
this._g.canDragBar=!0):(a.playdotDom.style.display="none",this._g.canDragBar=!1))):3==t?(v.removeClass(o,a.playingCss),
a.pauseCss&&v.removeClass(o,a.pauseCss),a.playdotDom&&(a.playdotDom.style.display="none",
this._g.canDragBar=!1),this._updateProgress(0)):(1==t||4==t)&&(a.allowPause?v.addClass(o,a.pauseCss||a.playingCss):v.addClass(o,a.playingCss),
a.playdotDom&&(e.surportSeekRange()?(a.playdotDom.style.display="block",this._g.canDragBar=!0):(a.playdotDom.style.display="none",
this._g.canDragBar=!1))),a.loadingDom&&(a.loadingDom.style.display=4==t?"block":"none");
},a.prototype._updateProgress=function(e){
this._g.barDraging||this._updateProgressBar(e);
},a.prototype._updateProgressBar=function(e){
var t=this._o,a=this.player,o=a.getDuration();
if(o){
var r=this._countProgress(o,e);
t.progress&&(t.progress.style.width=r),t.playtimeDom&&e>=0&&(t.playtimeDom.innerHTML=u(e)),
t.playdotDom&&(t.playdotDom.style.left=r);
}
},a.prototype._countProgress=function(e,t){
return Math.min(t/e*100,100)+"%";
},a.prototype.destory=function(){
this.player&&this.player.destory();
},a.prototype.setOption=function(e){
e.duration&&(this._g.seekData.duration=e.duration),this._extend(e);
},a.prototype.setMusicPlayerOption=function(e){
e.duration&&this._g&&this._g.seekData&&(this._g.seekData.duration=e.duration),this.player&&this.player.setOption(e);
},a.prototype.getBackgroundAudioState=function(e){
return this.player.getBackgroundAudioState(e);
},{
init:d,
renderPlayer:r,
formatTime:u,
decodeStr:_,
encodeStr:g
};
});define("pages/qqmusic_tpl.html.js",[],function(){
return'<span id="qqmusic_main_<#=musicid#>_<#=posIndex#>" class="js_wap_qqmusic db pages_reset music_area <#if(!musicSupport){#> unsupport<#}#>">\n    <span class="tc tips_global unsupport_tips" <#if(show_not_support!==true){#>style="display:none;"<#}#>>\n    当前浏览器不支持播放音乐或语音，请在微信或其他浏览器中播放    </span>\n    <span class="db music_card appmsg_card_context appmsg_card_active">\n            <a id="qqmusic_home_<#=musicid#>_<#=posIndex#>" class="music_card_bd">\n                <span class="music_card_title"><#=music_name#></span>\n                <span class="music_card_desc"><#=singer#></span>\n                <span class="music_card_source <#if(musictype==2){#>music_card_source_kugou<#}#>">\n                  <img src="<#=musicIcon#>" alt=""></span>\n            </a>\n            <span id="qqmusic_play_<#=musicid#>_<#=posIndex#>" class="music_card_ft">\n                <i class="weui-play-btn"></i>\n                <!--\n                <img src="<#=window.icon_qqmusic_default#>" alt="" class="pic_qqmusic_default">\n                -->\n                <img src="<#=albumurl#>" data-autourl="<#=audiourl#>" data-musicid="<#=musicid#>" class="music_card_thumb" alt="">\n            </span>\n    </span>\n</span>\n';
});define("new_video/ctl.js",["common/comm_report.js","biz_wap/utils/ajax.js"],function(e){
"use strict";
var i,n=e("common/comm_report.js");
if(parent==window)i=window;else try{
{
parent.window.location.href;
}
i=parent.window;
}catch(r){
i=window;
}
var t=i.user_uin,a=Math.floor(i.user_uin/100)%20;
t||(a=-1);
var o=function(){
return a>=0;
};
i.__webviewid||(i.__webviewid=+new Date+"_"+Math.ceil(1e3*Math.random()));
var d=function(){
var e=i.mid,n=i.idx,r="";
r=e&&n?e+"_"+n:"";
var a=i.__webviewid,o=[t,r,a].join("_");
return o;
},s=function(i){
if(20>a)try{
var n=i.vid||"",r={};
r.__biz=parent.window.biz||"",r.vid=n,r.clienttime=+new Date;
var t=parent.window.mid,s=parent.window.idx,p="";
p=t&&s?t+"_"+s:n,r.type="undefined"!=typeof i.type?i.type:t&&s?1:2,r.id=p,r.hit_bizuin=i.hit_bizuin||"",
r.hit_vid=i.hit_vid||"",r.webviewid=d(),r.step=i.step||0,r.orderid=i.orderid||0,
r.ad_source=i.ad_source||0,r.traceid=i.traceid||0,r.ext1=i.ext1||"",r.ext2=i.ext2||"",
r.r=Math.random(),r.devicetype=parent.window.devicetype,r.version=parent.window.clientversion,
r.is_gray=o()?1:0,r.mid=t||"",r.idx=s||"",r.url=parent.window.location.href,r.screen_num=i.screen_num||0,
r.screen_height=i.screen_height||0,r.ori_status=i.ori_status||3,r.fromid=i.fromid||0,
r.sessionid=window.sessionid||"",r.appmsg_scene=window.source||(window.cgiData?window.cgiData.scene:0)||0,
!r.appmsg_scene&&r.fromid?r.appmsg_scene=r.fromid:!r.fromid&&r.appmsg_scene&&(r.fromid=r.appmsg_scene),
r.total_range=i.total_range||0,r.current_range=i.current_range||0,r.duration=i.duration||0;
var c=e("biz_wap/utils/ajax.js");
c({
url:"/mp/ad_video_report?action=user_action",
type:"post",
data:r
});
}catch(w){}
},p=function(e){
try{
var i=e.vid||"",r={};
r.BizUin=parent.window.biz||"",r.Vid=i,r.ClientTime=+new Date;
var t=parent.window.mid,a=parent.window.idx,s="";
s=t&&a?t+"_"+a:i,r.Type="undefined"!=typeof e.type?e.type:t&&a?1:2,r.Id=s,r.HitBizUin=parseInt(e.hit_bizuin)||0,
r.HitVid=e.hit_vid||"",r.WebViewId=d(),r.Step=parseInt(e.step,10)||0,r.OrderId=(e.orderid||"").toString(),
r.AdSource=parseInt(e.ad_source,10)||0,r.TraceId=(e.traceid||"").toString(),r.Ext1=(e.ext1||"").toString(),
r.Ext2=(e.ext2||"").toString(),r.r=Math.random(),r.DeviceType=parent.window.devicetype,
r.ClientVersion=parseInt(parent.window.clientversion),r.IsGray=o()?1:0,r.msgid=parseInt(t,10)||0,
r.itemidx=parseInt(a,10)||0,r.Url=parent.window.location.href,r.ScreenNum=parseInt(e.screen_num,10)||0,
r.ScreenHeight=parseInt(e.screen_height,10)||0,r.OrStatus=parseInt(e.ori_status,10)||3,
r.Fromid=parseInt(e.fromid,10)||0,r.SessionId=(window.sessionid||"").toString(),
r.AppmsgScene=parseInt(window.source||(window.cgiData?window.cgiData.scene:0),10)||0,
!r.AppmsgScene&&r.Fromid?r.AppmsgScene=r.Fromid:!r.Fromid&&r.AppmsgScene&&(r.Fromid=r.AppmsgScene),
r.AppmsgScene=parseInt(r.AppmsgScene,10)||0,r.Fromid=parseInt(r.Fromid,10)||0,r.TotalRange=parseInt(e.total_range,10)||0,
r.CurrentRange=parseInt(e.current_range,10)||0,r.Duration=parseInt(e.duration,10)||0,
r.RemindTrafficSize=parseInt(e.remind_traffic_size,10)||0,r.TrafficReminderType=parseInt(e.traffic_reminder_type,10)||0,
n.report(12710,r);
}catch(p){}
};
return{
report:s,
getWebviewid:d,
showAd:o,
commReport:p
};
});define("biz_wap/jsapi/leaveReport.js",["biz_wap/utils/ajax.js","biz_wap/jsapi/core.js","biz_common/utils/url/parse.js","biz_wap/utils/log.js"],function(e){
"use strict";
function t(e){
var t={};
return"undefined"!=typeof uin&&(t.uin=uin),"undefined"!=typeof key&&(t.key=key),
"undefined"!=typeof pass_ticket&&(t.pass_ticket=pass_ticket),"undefined"!=typeof wxtoken&&(t.wxtoken=wxtoken),
"undefined"!=typeof window.devicetype&&(t.devicetype=window.devicetype),"undefined"!=typeof window.clientversion&&(t.clientversion=window.clientversion),
"undefined"!=typeof appmsg_token?t.appmsg_token=appmsg_token:e.indexOf("advertisement_report")>-1&&((new Image).src=location.protocol+"//mp.weixin.qq.com/mp/jsmonitor?idkey=68064_13_1&r="+Math.random()),
t.x5=l?"1":"0",t.f="json",f.join(e,t);
}
function o(e){
return e&&"object"==typeof e;
}
function n(e,t){
if(o(e)&&o(t))for(var n in t)Object.prototype.hasOwnProperty.call(t,n)&&(e[n]=t[n]);
}
function r(e){
u("[leaveReport 1]"),console.log("[leaveReport 1]");
var r={};
for(var i in y){
r[i]||(r[i]={});
for(var a=0;a<y[i].length;a++){
var p=y[i][a];
"function"==typeof p?n(r[i],p(e)):o(p)&&n(r[i],p);
}
}
u("[leaveReport getDataFunc.length "+_.length+"]"),console.log("[leaveReport getDataFunc.length "+_.length+"]");
for(var a=0;a<_.length;a++){
var s=_[a](e);
o(s)&&g.push(s);
}
for(var a=0;a<g.length;a++)g[a].reportUrl&&(g[a].reportUrl=t(g[a].reportUrl));
return r.data={
requestList:g
},r;
}
function i(e){
"function"==typeof e?_.push(e):o(e)&&g.push(e);
}
function a(e,t){
y[e]||(y[e]=[]),y[e].push(t);
}
function p(e){
var t=r(!0);
c.invoke("handleMPPageAction",{
action:"reportByLeaveForMPGateway",
reportData:t
},function(o){
if(o&&o.err_msg&&-1!==o.err_msg.indexOf(":ok"))_=[],y={},"function"==typeof e&&e(o);else{
_=[];
var n=t.data.requestList.length;
t.data.requestList.forEach(function(t){
t.reportUrl&&s({
type:t.method||"GET",
url:t.reportUrl,
data:t.reportData,
async:!1,
success:function(t){
--n<0&&"function"==typeof e&&e({
err_msg:"handleMPPageAction:ok",
fallback:!0,
resp:t
});
},
error:function(t,o){
--n<0&&"function"==typeof e&&e({
err_msg:"handleMPPageAction:fail",
fallback:!0,
err:o
});
}
});
});
}
});
}
var s=e("biz_wap/utils/ajax.js"),c=e("biz_wap/jsapi/core.js"),f=e("biz_common/utils/url/parse.js"),u=e("biz_wap/utils/log.js"),l=-1!=navigator.userAgent.indexOf("TBS/"),d={},v=!1;
try{
d=top.window.document;
}catch(w){
v=!0;
}
if(!v&&top.window.__leaveReport)return top.window.__leaveReport;
if(window.__leaveReport)return window.__leaveReport;
var _=[],g=[],y={};
c.on("reportOnLeaveForMP",function(){
return r(!1);
});
var h={
reportNow:p,
addReport:i,
addSpecificReport:a
};
return window.__leaveReport=h,h;
});define("biz_wap/utils/hand_up_state.js",["biz_common/dom/event.js"],function(n){
"use strict";
function e(){
if("hidden"in document)return"hidden";
for(var n=["webkit","moz","ms","o"],e=0;e<n.length;e++)return n[e]+"Hidden"in document,
n[e]+"Hidden";
return null;
}
function i(){
var n=e();
return n?document[n]:!1;
}
function t(){
return r;
}
var d=n("biz_common/dom/event.js"),o=e(),r=0,u=0;
if(o){
var m=o.replace(/[H|h]idden/,"")+"visibilitychange";
d.on(document,m,function(){
i()?u=(new Date).getTime():r+=(new Date).getTime()-u;
},!1);
}
return{
getHandUpTime:t,
isHidden:i
};
});define("biz_common/utils/http.js",[],function(){
"use strict";
function t(){
var t=document.getElementsByTagName("html");
if(t&&1==!!t.length){
t=t[0].innerHTML;
var e=t.replace(/[\x00-\xff]/g,""),n=t.replace(/[^\x00-\xff]/g,"");
return 1*n.length+3*e.length+"<!DOCTYPE html><html></html>".length;
}
return 0;
}
return{
htmlSize:t()
};
});define("biz_common/utils/cookie.js",[],function(){
"use strict";
var e={
get:function(e){
if(""==e)return"";
var t=new RegExp(e+"=([^;]*)"),n=document.cookie.match(t);
return n&&n[1]||"";
},
set:function(e,t,n){
var o=new Date;
return o.setDate(o.getDate()+(n||1)),n=o.toGMTString(),document.cookie=e+"="+t+";expires="+n,
!0;
}
};
return e;
});define("appmsg/open_url_with_webview.js",["biz_wap/jsapi/core.js"],function(e){
"use strict";
var r=e("biz_wap/jsapi/core.js"),n=-1!=navigator.userAgent.indexOf("WindowsWechat"),i=function(e,i){
if(n)return location.href=e,!1;
i=i||{};
var o=i.sample||0;
o*=1e3;
var t=window.user_uin||0,s=0!==t&&Math.floor(t/100)%1e3<o;
return s?void r.invoke("openUrlWithExtraWebview",{
url:e,
openType:i.openType||1,
scene:i.scene||"",
bizUsername:i.user_name||""
},function(e){
e&&"openUrlWithExtraWebview:ok"===e.err_msg?i.resolve&&i.resolve():i.reject&&i.reject();
}):void(i.reject&&i.reject());
};
return i;
});var _extends=Object.assign||function(e){
for(var n=1;n<arguments.length;n++){
var i=arguments[n];
for(var t in i)Object.prototype.hasOwnProperty.call(i,t)&&(e[t]=i[t]);
}
return e;
};
define("appmsg/album_keep_read.js",["page/appmsg_new/mod/album_read.css","biz_common/dom/event.js","biz_common/dom/class.js","pages/mod/bottom_modal.js","biz_wap/utils/openUrl.js","pages/utils.js","biz_wap/utils/ajax.js","common/comm_report.js","common/utils.js","biz_common/dom/offset.js","biz_wap/utils/wapsdk.js"],function(e){
"use strict";
function n(e,n){
v.jsmonitor({
id:223326,
key:e,
value:n
});
}
function i(){
var e=arguments.length<=0||void 0===arguments[0]?{}:arguments[0];
b.report(21277,_extends({},x,e));
}
function t(){
function e(){
if(!t){
var e=w.getOffset(h).offsetTop,o=f.getScrollTop();
o+f.getInnerHeight()>=e+a&&e+a>=o&&(i({
ActionType:1
}),n(11),t=!0);
}
}
var t=void 0,a=h.offsetHeight/2;
f.bindDebounceScrollEvent(e),e();
}
function a(){
var e=window.appmsg_album_info;
if(e.link){
var n=e.link.replace("#wechat_redirect","&subscene=159&subscene="+window.source+"&scenenote="+encodeURIComponent(window.location.href)+"#wechat_redirect");
_.openUrlWithExtraWebview(n.htmlDecode());
}
}
function o(e){
e&&c.on(e,"click","."+y.itemClassName,function(e){
var n=e.delegatedTarget;
if(!u.hasClass(n,"album_read_directory_current")){
var t=void 0;
t=n.dataset.url.includes("#")?n.dataset.url.replace("#",T+"&scene=190#"):n.dataset.url+(T+"&scene=190"),
i({
ActionType:5,
Url:t
}),p.jumpUrl(t,!0),u.addClass(n,"album_read_directory_disabled");
}
});
}
function s(){
var e=document.createElement("div"),n=document.createElement("span");
return n.innerHTML="#"+window.appmsg_album_info.title,e.appendChild(n),e.innerHTML;
}
function r(e){
g({
type:"GET",
url:"/mp/appmsgalbum?action=paging&__biz="+window.biz+"&album_id="+y.albumId+"&cur_msgid="+y.msgid+"&cur_itemidx="+y.idx+"&count="+y.pageCount,
timeout:5e3,
dataType:"json",
success:function(n){
n.base_resp&&0===n.base_resp.ret&&e(n.getalbum_resp);
},
error:function(){
console.log("[error]");
}
});
}
function l(){
function e(e){
var n=arguments.length<=1||void 0===arguments[1]?!1:arguments[1],i=arguments.length<=2||void 0===arguments[2]?!0:arguments[2],t=document.createDocumentFragment();
if(_)if(n){
h=1;
for(var a=0;a<e.length;a++)if(e[a].msgid.toString()===y.msgid.toString()&&e[a].itemidx.toString()===y.idx.toString()){
h=a;
break;
}
e.forEach(function(e,n){
e.index=p?c-(n-h):c+(n-h);
});
}else e.forEach(i?function(e,n){
e.index=p?v.index-n-1:v.index+n+1;
}:function(n,i){
n.index=p?w.index+(e.length-i):w.index-(e.length-i);
});
return e.forEach(function(e){
var n=document.createElement("div");
if(u.addClass(n,y.itemClassName),e.msgid.toString()===window.mid.toString()&&e.itemidx.toString()===window.idx.toString()?u.addClass(n,"album_read_directory_current"):1===e.user_read_status&&u.addClass(n,"album_read_directory_disabled"),
n.innerText=_?e.index+"."+e.title:e.title,n.setAttribute("data-url",e.url),e.is_paid){
var i="已付费";
n.innerHTML+='<span class="wx_icon_pay_tag wx_icon_pay_tag_paid">'+i+"</span>";
}else if(e.is_pay_subscribe){
var a="付费";
n.innerHTML+='<span class="wx_icon_pay_tag">'+a+"</span>";
}
t.appendChild(n);
}),t;
}
function t(e){
1*e.reverse_continue_flag||(b=!1),1*e.continue_flag||(f=!1);
}
var l=document.createElement("div");
l.style.position="relative";
var d=[],c=void 0,_=void 0,p=void 0,b=!0,f=!0,w=void 0,v=void 0,h=1,x={
extClass:"album_read_directory",
hasBtn:!0,
btnSlot:'<div id="js_topic_detail" class="weui-btn__word-wrp">\n                  <span class="weui-btn__word">详情</span>\n                  <i class="weui_right_arrow"></i>\n                </div>',
title:s(),
btnClickCb:function(){
i({
ActionType:6
}),n(15),a();
},
cb:function(){
r(function(n){
j.hideLoading(),p=n.base_info.is_reverse,c=n.base_info.cur_article_num,_=c?1:0,l.appendChild(e(n.article_list,!0)),
w=n.article_list[0],v=n.article_list[n.article_list.length-1],t(n),f||j.showEndLine();
var i=l.childNodes[h];
setTimeout(function(){
i.offsetTop+i.clientHeight>j.contentAreaWrp.clientHeight&&j.scrollTo(0,l.offsetHeight);
},200);
});
},
onShow:function(){
i({
ActionType:4
}),n(14);
},
onPullUpLoad:function(){
f&&(j.showPullUpLoading(),g({
type:"GET",
url:"/mp/appmsgalbum?action=paging&__biz="+window.biz+"&album_id="+y.albumId+"&begin_msgid="+v.msgid+"&begin_itemidx="+v.itemidx+"&count="+y.pageCount,
timeout:5e3,
dataType:"json",
success:function(n){
j.hidePullUpLoading();
var i=n.base_resp&&1*n.base_resp.ret;
if(0===i){
var a=n.getalbum_resp.article_list;
t(n.getalbum_resp),l.appendChild(e(a,!1,!0)),d=d.concat(a),j.finishPullUpLoad(),
v=d[d.length-1],1*n.getalbum_resp.continue_flag||j.showEndLine();
}
},
error:function(){}
}));
},
onPullDownLoad:function(){
b&&(j.showPullDownLoading(),g({
type:"GET",
url:"/mp/appmsgalbum?action=paging&__biz="+window.biz+"&album_id="+y.albumId+"&begin_msgid="+w.msgid+"&begin_itemidx="+w.itemidx+"&count="+y.pageCount+"&isbackward=1",
timeout:5e3,
dataType:"json",
success:function(n){
j.hidePullDownLoading();
var i=n.base_resp&&1*n.base_resp.ret;
if(0===i){
var a=n.getalbum_resp.article_list,o=n.getalbum_resp.continue_flag;
n.getalbum_resp.continue_flag=n.getalbum_resp.reverse_continue_flag,n.getalbum_resp.reverse_continue_flag=o,
t(n.getalbum_resp);
var s=e(a,!1,!1),r=l.firstChild;
l.insertBefore(s,r),d=a.concat(d),j.scrollTo(0,r.offsetTop-69),j.finishPullDownLoad(),
w=d[0];
}
},
error:function(){}
}));
}
};
window.appmsg_album_info.size<=4&&(x.top=screen.height/2-(screen.height-window.innerHeight)+"px"),
j=new m(l,x),j.showLoading(),j.show(),o(l);
}
function d(){
var e=arguments.length<=0||void 0===arguments[0]?{}:arguments[0],t=document.getElementById("js_album_directory");
c.on(t,"click",function(){
j?j.show():l();
});
var a=document.getElementById("js_album_prev"),o=document.getElementById("js_album_next");
e.pre_article_link?c.on(a,"click",function(){
var t=void 0;
i({
ActionType:2,
SubActionType:1
}),n(12),t=e.pre_article_link.includes("#")?e.pre_article_link.replace("#",T+"&scene=189#"):e.pre_article_link+(T+"&scene=189"),
location.href=t.replace(/&amp;/g,"&");
}):a.parentNode.removeChild(a),e.next_article_link?c.on(o,"click",function(){
var t=void 0;
i({
ActionType:2,
SubActionType:2
}),n(13),t=e.next_article_link.includes("#")?e.next_article_link.replace("#",T+"&scene=189#"):e.next_article_link+(T+"&scene=189"),
location.href=t.replace(/&amp;/g,"&");
}):o.parentNode.removeChild(o);
}
e("page/appmsg_new/mod/album_read.css");
var c=e("biz_common/dom/event.js"),u=e("biz_common/dom/class.js"),m=e("pages/mod/bottom_modal.js"),_=e("biz_wap/utils/openUrl.js"),p=e("pages/utils.js"),g=e("biz_wap/utils/ajax.js"),b=e("common/comm_report.js"),f=e("common/utils.js"),w=e("biz_common/dom/offset.js"),v=e("biz_wap/utils/wapsdk.js"),h=document.getElementById("js_album_keep_read"),y={
link:window.appmsg_album_info.link,
albumId:window.appmsg_album_info.id,
msgid:window.mid,
idx:window.idx,
pageCount:10,
itemClassName:"album_read_directory_item"
},x={
MsgId:1*y.msgid,
ItemIdx:1*y.idx,
BizUin:window.biz,
Itemshowtype:1*window.item_show_type,
SessionId:window.sessionid,
EnterId:1*window.enterid,
Scene:1*window.source,
SubScene:1*window.subscene,
Albumid:y.albumId,
Albumtype:window.appmsg_album_info.type,
Title:window.appmsg_album_info.title
},j=void 0,T="&cur_album_id="+y.albumId;
return{
init:function(e){
h&&(e.pre_article_link||e.next_article_link)&&(document.getElementById("js_album_keep_read_title").innerHTML=window.appmsg_album_info.title,
document.getElementById("js_album_keep_read_size").innerHTML=window.appmsg_album_info.size,
document.getElementById("js_album_keep_read_pre_title").innerHTML=e.pre_article_title||"",
document.getElementById("js_album_keep_read_next_title").innerHTML=e.next_article_title||"",
h.style.display="block",d(e),t());
}
};
});define("appmsg/more_read.js",["biz_common/utils/string/html.js","biz_common/tmpl.js","biz_wap/utils/ajax.js","appmsg/more_read_tpl.html.js","biz_wap/utils/openUrl.js","biz_common/dom/event.js","biz_wap/utils/jsmonitor_report.js","common/utils.js"],function(n){
"use strict";
function i(n){
for(var i=r.getInnerHeight(),e=document.documentElement.clientWidth||window.innerWidth,t=document.body.scrollHeight||document.body.offsetHeight,s=document.body.scrollTop||document.documentElement.scrollTop,m=[],a=0;a<l.length;a++){
var w=[l[a].bizuin||window.biz||"",l[a].mid||"",l[a].idx||""].join("_");
m.push(w);
}
m=m.join("#");
var p=c[n.index].getBoundingClientRect(),h="fans_read_cnt="+l[n.index].fans_read_cnt,g={
act:n.action||0,
bizuin:window.biz||"",
msgid:window.mid||"",
idx:window.idx||"",
scene:window.source||"",
sub_scene:window.subscene||"",
get_a8_key_scene:window.ascene||"",
screen_height:i,
screen_width:e,
screen_num:Math.ceil(t/i),
action_screen_num:Math.ceil((p.top+p.height+s)/i),
start_time_ms:_,
action_time_ms:Date.now(),
more_msg:m,
a_bizuin:l[n.index].bizuin||window.biz||"",
a_msgid:l[n.index].mid||"",
a_idx:l[n.index].idx||"",
rank:n.index+1,
tip:h,
session_id:u
};
o({
url:"/mp/appmsgreport?action=more_read",
type:"POST",
data:g,
timeout:2e3,
async:!1,
mayAbort:!0
});
var b=1===n.action?4:5;
d.setSum(110809,b,1);
}
function e(){
if(l){
for(var n=0,t=r.getInnerHeight(),o=0;o<c.length;o++)if(c[o].dataset.show)n++;else{
var s=c[o].getBoundingClientRect();
s.top+s.height<t&&(c[o].dataset.show=1,i({
action:1,
index:o
}));
}
n>=c.length&&a.off(window,"scroll",e);
}
}
n("biz_common/utils/string/html.js");
var t=n("biz_common/tmpl.js"),o=n("biz_wap/utils/ajax.js"),s=n("appmsg/more_read_tpl.html.js"),m=n("biz_wap/utils/openUrl.js"),a=n("biz_common/dom/event.js"),d=n("biz_wap/utils/jsmonitor_report.js"),r=n("common/utils.js"),l=null,c=null,_=Date.now(),u=""+_+"_"+Math.random().toString(36).substring(2);
return a.on(window,"scroll",e),function(n,e){
l=e,n.innerHTML=t.tmpl(s,{
list:l
},!1),c=n.getElementsByClassName("more_read_link");
for(var o=0;o<c.length;o++)a.on(c[o],"click",function(n){
return function(){
window.__second_open__?m.openUrlWithExtraWebview(l[n].link.htmlDecode()):window.location.href=l[n].link.htmlDecode(),
i({
action:2,
index:n
});
};
}(o));
n.style.display="";
};
});var _extends=Object.assign||function(e){
for(var t=1;t<arguments.length;t++){
var n=arguments[t];
for(var o in n)Object.prototype.hasOwnProperty.call(n,o)&&(e[o]=n[o]);
}
return e;
};
define("appmsg/comment.js",["biz_wap/ui/weui.js","biz_common/utils/string/html.js","biz_common/utils/wxgspeedsdk.js","appmsg/comment_report.js","biz_wap/utils/device.js","biz_common/utils/url/parse.js","biz_wap/jsapi/core.js","common/utils.js","biz_common/dom/event.js","biz_wap/utils/ajax.js","biz_common/tmpl.js","biz_wap/utils/fakehash.js","appmsg/log.js","appmsg/comment/comment_tpl.html.js","appmsg/comment/comment_write.html.js","appmsg/comment/comment_write_old.html.js","pages/utils.js","biz_wap/utils/mmversion.js","common/comm_report.js","appmsg/set_font_size.js","biz_wap/utils/jsmonitor_report.js","common/keyboard.js","appmsg/comment/comment_list/comment_list.js","appmsg/comment/comment_dialog/comment_dialog.js","appmsg/comment/comment_input/comment_input.js","pages/scrollY.js","appmsg/comment/comment_report.js","pages_new/common_share/video/store.js"],function(e){
"use strict";
e("biz_wap/ui/weui.js"),e("biz_common/utils/string/html.js");
var t=e("biz_common/utils/wxgspeedsdk.js"),n=e("appmsg/comment_report.js"),o=e("biz_wap/utils/device.js"),i=e("biz_common/utils/url/parse.js"),s=e("biz_wap/jsapi/core.js"),m=e("common/utils.js"),a=e("biz_common/dom/event.js"),c=e("biz_wap/utils/ajax.js"),d=e("biz_common/tmpl.js"),r=e("biz_wap/utils/fakehash.js"),l=e("appmsg/log.js"),p=e("appmsg/comment/comment_tpl.html.js"),_=e("appmsg/comment/comment_write.html.js"),u=e("appmsg/comment/comment_write_old.html.js"),w=e("pages/utils.js"),y=e("biz_wap/utils/mmversion.js"),g=e("common/comm_report.js"),f=e("appmsg/set_font_size.js"),I=e("biz_wap/utils/jsmonitor_report.js"),C=e("common/keyboard.js"),b=e("appmsg/comment/comment_list/comment_list.js"),h=e("appmsg/comment/comment_dialog/comment_dialog.js"),j=e("appmsg/comment/comment_input/comment_input.js"),v=e("pages/scrollY.js"),k=e("appmsg/comment/comment_report.js"),L=k.report22214,D=!window.isPaySubscribe||window.isPaySubscribe&&window.isPaid,R=m.getInnerHeight(),x=0;
try{
x=1*window.atob(window.biz);
}catch(T){}
var F={
BizUin:x,
BizUinStr:window.biz||"",
AppMsgId:window.parseInt(window.mid,10)||0,
ItemIdx:window.parseInt(window.idx,10)||0,
ItemShowType:window.parseInt(window.item_show_type,10)||0,
SessionIdStr:window.sessionid||"",
EnterId:window.parseInt(window.enterid,10)||0,
Scene:window.parseInt(window.source,10)||0,
SubScene:window.parseInt(window.subscene,10)||0
},S={
bizuin:x,
msgid:window.parseInt(window.mid,10)||0,
itemidx:window.parseInt(window.idx,10)||0,
scene:window.parseInt(window.source,10)||0
},P=!1,z=void 0,E=void 0,A=void 0,B=void 0,N=!1,M=[],O={},H=0,U=Date.now(),W=[],K=null,G="",Y=!1,q=!1,V=!1,J={
commentCount:"",
scrollCount:0,
nickName:"我",
headImg:"",
offset:0,
commentId:window.comment_id,
onlyFansCanComment:0,
onlyFansDaysCanComment:0,
isFans:0,
isFansDays:0,
replyFlag:0,
reportData:{
scene:0,
idkey:"",
moreList:27,
repeatList:25,
errList:18,
handleList:26,
addCommentErr:19,
errComment:18,
repeatContent:24,
repeatContentID:23
},
contentIDs:[],
canC2CReply:!1,
cmtDialog:null,
cmtList:null,
myList:null
},Q=100,X=location.href,Z=y.is_wxwork,$=o.os.pc&&!Z,et="comment_editing",tt="my_comment_empty_data",nt=navigator.userAgent.indexOf("MicroMessenger")>-1,ot=w.getId("js_cmt_area"),it=X.indexOf("vconsole=1")>0||document.cookie&&document.cookie.indexOf("vconsole_open=1")>-1,st=w.getId("activity-name")||"";
st&&(st=w.trim(st.innerText)||""),window.pageCommentReportData&&window.pageCommentReportData.idkey&&(it&&console.log("init reportData"),
J.reportData=window.pageCommentReportData),"undefined"!=typeof window.comment_id?J.commentId=window.comment_id:window.cgiData&&"undefined"!=typeof window.cgiData.comment_id&&(J.commentId=window.cgiData.comment_id),
nt||(ot&&(ot.style.display="none"),J.commentId=0),it&&console.info("[图文评论] 评论ID:",J.commentId);
var mt=function(){
return y.isWechat?o.os.ipad?0:y.isInMiniProgram?0:C.canUseKeyboard?2:(y.isIOS||y.isAndroid)&&(y.gtVersion("7.0.8")||m.isNativePage())?1:0:0;
}(),at=function(e,t){
e&&(e.style.display=t||"block");
},ct=function(e){
e&&(e.style.display="none");
},dt=function(e){
if(!e)return!1;
var t=m.getScrollTop(),n=e.offsetTop;
return t+R>n&&n>=t;
},rt=function(e,n){
Math.random()<.999||(t.saveSpeeds({
uin:window.uin,
pid:"https:"===window.location.protocol?18:9,
speeds:[{
sid:29,
time:e
},{
sid:30,
time:n
}]
}),t.send());
},lt=function(e){
var t=arguments.length<=1||void 0===arguments[1]?"":arguments[1];
if("undefined"!=typeof e)if(J.reportData.idkey)I.setSum(J.reportData.idkey,e,1);else{
var n=new Image,o=Math.random();
n.src="/mp/jsreport?key="+e+"&content="+t+"&r="+o;
}
},pt=function(){
Array.prototype.forEach.call(w.getByClass("js_more_reply"),function(e){
var t=e.dataset.myId;
-1===W.indexOf(t)&&dt(e)&&(g.report(19462,_extends({
PersonalCommentId:parseInt(t,10)||0,
CommentId:parseInt(J.commentId,10)||0,
actiontype:1,
wording:"余下N条",
number:parseInt(e.dataset.num,10)||0,
devicetype:$?1:2
},S)),W.push(t));
});
},_t=function(){
2>H||[J.myList.getItemList(),J.cmtList.getItemList()].forEach(function(e,t){
var n=J[t?"cmtList":"myList"];
e.some(function(e){
if(!e.isExposed){
var o=e.getBoundingClientRect(),i=.5*o.height;
if(o.bottom>i&&o.top<R-i){
e.isExposed=!0;
var s=e.dataset,m={
PersonalCommentId:1*s.myId,
ReplyId:0,
IsPopup:0,
IsReplyOther:0,
CommentReplyType:t?1:2
};
if(s.replyId){
var a=n.getData({
type:"reply",
contentId:s.contentId,
replyId:1*s.replyId
});
m.ReplyId=a.reply_id,m.IsReplyOther=a.to_nick_name&&a.to_content?1:0;
}
L(m);
}else if(o.top>=R-i)return!0;
}
return!1;
});
});
},ut=function(){
E||(E=!0,new n({
comment_id:J.commentId,
appmsgid:window.appmsgid,
idx:window.idx,
item_show_type:window.item_show_type||0,
biz:window.biz
}),pt());
},wt=function Et(){
try{
dt(O.loading)&&N&&(I.setLogs({
id:28307,
key:45,
value:1,
lc:1,
log0:""
}),a.off(window,"scroll",Et));
}catch(e){
console.error(e);
}
},yt=function(){
J.myList.showAll(),_t(),O.mylistFolder&&(O.mylistFolder.parentNode.removeChild(O.mylistFolder),
O.mylistFolder=null);
},gt=function(){
var e=!0,t=!0,n=!1,o=null,i=null,s=null,m=function(e){
e&&window.scrollTo(0,e.getBoundingClientRect().top+w.getScrollTop()-6);
};
return function(a,c){
if(e&&window.goContentId&&!c&&a)if(!window.onload_endtime||new Date-window.onload_endtime<1e3){
if(q&&(null===o&&(o=null!==J.myList.getData({
contentId:window.goContentId
})),o))return void("none"!==ot.style.display&&(yt(),m(""!==window.goReplyId?J.myList.getReply(window.goContentId,1*window.goReplyId):J.myList.getComment(window.goContentId)),
e=!1));
Y&&(null===i&&(s=J.cmtList.getData({
contentId:window.goContentId
}),i=null!==s),i&&(t&&""!==window.goReplyId&&(s.reply_new.reply_total_cnt&&s.reply_new.reply_total_cnt!==s.reply_new.reply_list.length?J.cmtDialog.showDialog(J.cmtList.getData({
contentId:window.goContentId
}),1*window.goReplyId):n=!0,t=!1),q&&(m(n?J.cmtList.getReply(window.goContentId,1*window.goReplyId):J.cmtList.getComment(window.goContentId)),
e=!1)));
}else e=!1;
};
}(),ft=function(e,t){
J.onlyFansDaysCanComment&&0===J.isFansDays?((t||e).innerHTML="作者已设置关注7天后才可留言",at(e,"block")):J.onlyFansCanComment&&0===J.isFans?((t||e).innerHTML="作者已设置关注后才可以留言",
at(e,"block")):D&&($?(at(O.commentPC),at(O.inputPC)):at(O.addBtn,"flex"));
},It=function(e){
var n=Date.now(),o=e.resp,i=e.loadTime,s=e.forceRefresh,m=e.notFirstRender;
if(J.onlyFansCanComment=o.only_fans_can_comment,J.isFans=o.is_fans,J.replyFlag=J.canC2CReply?o.reply_flag:0,
lt(J.reportData.handleList,encodeURIComponent(JSON.stringify({
comment_id:J.commentId,
offset:J.offset,
url:X
}))),1!==o.enabled?(ot&&(ot.style.display="none"),o.elected_comment=[],o.elected_comment_total_cnt=0):ot&&(ot.style.display="block"),
0===J.offset){
J.headImg=o.logo_url,J.nickName=o.nick_name,s&&(J.contentIDs=[]);
var a=o.elected_comment;
a&&a.length?(at(O.main),J.cmtList.render(a),!Z&&ft(w.getId("js_cmt_nofans1")),o.elected_comment_total_cnt<=10&&at(O.statement),
A||"5"!==window.item_show_type||(A=!0,Math.random()<.1&&(t.saveSpeeds({
uin:window.uin,
pid:675,
speeds:[{
sid:27,
time:Date.now()-window.logs.pagetime.page_begin
}]
}),t.send())),Y=!0,gt(s,m)):(ct(O.main),!Z&&ft(w.getId("js_cmt_nofans2"),w.getId("js_cmt_nofans2_inner")));
var c=ot.getBoundingClientRect().y;
location.href.indexOf("scrolltodown")>-1&&c&&window.scrollTo(0,c-25);
}else{
var a=o.elected_comment;
a&&a.length&&J.cmtList.add({
data:a
});
}
0===o.elected_comment_total_cnt?(J.offset=-1,ct(O.loading),ct(O.statement)):J.offset+Q>=o.elected_comment_total_cnt?(J.offset=-1,
ct(O.loading),at(O.statement)):J.offset+=o.elected_comment.length,window.ipados13_font_scale&&f.setFontSize(O.main,window.ipados13_font_scale/100),
ut(),w.setTwoTabHeight("js_comment_content"),i&&rt(i,Date.now()-n);
},Ct=function(e){
if(J.commentId=window.comment_id,0!==Number(J.commentId)){
var t=e.notFirstRender,n=e.forceRefresh,o=e.cb;
n=n===!0,n&&(J.offset=0);
var s=m.getScrollTop(),d=document.documentElement.scrollHeight;
if(!(N||-1===J.offset||J.offset>0&&d-s-R>500)){
if("number"==typeof J.commentCount&&0===J.commentCount&&!n)return void It({
resp:{
enabled:1,
elected_comment:[],
elected_comment_total_cnt:0,
my_comment:[],
only_fans_can_comment:J.onlyFansCanComment,
is_fans:J.isFans,
logo_url:J.headImg,
nick_name:J.nickName
}
});
var r=i.join("/mp/appmsg_comment",{
action:"getcomment",
scene:J.reportData.scene,
appmsgid:window.appmsgid,
idx:window.idx,
comment_id:J.commentId,
offset:J.offset,
limit:Q,
send_time:window.send_time
},!0),p=+new Date;
N=!0,at(O.loading),wt();
try{
J.scrollCount++,n&&(M=[]),J.scrollCount>1&&!n&&lt(J.reportData.moreList,encodeURIComponent(r)),
M.indexOf(r)>-1&&lt(J.reportData.repeatList,encodeURIComponent(r)),M.push(r);
}catch(_){
console.error(_);
}
it&&console.info("[图文评论] 开始请求评论数据:",r),l("[Appmsg comment] start get comment data, url:"+r),
c({
url:r,
dataType:"json",
success:function(e){
var i=e.base_resp&&e.base_resp.ret;
0===i?o&&o({
resp:e,
forceRefresh:n,
notFirstRender:t,
loadTime:Date.now()-p
}):lt(J.reportData.errList,"type:resperr;url:"+encodeURIComponent(r)+";ret="+i),
l("[Appmsg comment] get comment success");
},
error:function(){
lt(J.reportData.errList,"type:ajaxerr;url:"+encodeURIComponent(r)),l("[Appmsg comment] get comment ajax error");
},
complete:function(){
N=!1,ct(O.loading),a.off(window,"scroll",wt);
}
});
}
}
},bt=function(e){
var t=b.validContent(e);
return t.valid&&$&&(t.content=K.value),t;
},ht=function(e){
var t=e.content,n=e.successBegin,o=e.successEnd,s=e.complete;
z!==t&&(U=Date.now());
var m=i.join("/mp/appmsg_comment",{
action:"addcomment",
scene:J.reportData.scene,
appmsgid:window.appmsgid,
idx:window.idx,
comment_id:J.commentId,
sn:window.sn
},!0);
c({
url:m,
data:{
content:t,
title:st,
head_img:J.headImg,
nickname:J.nickName,
client_id:U
},
type:"POST",
dataType:"json",
success:function(e){
switch("function"==typeof n&&n(),+e.ret){
case 0:
window.weui.toast("已留言",750);
var i={
content:t,
nick_name:J.nickName,
create_time:Date.now()/1e3|0,
is_elected:0,
logo_url:J.headImg,
like_status:0,
like_num_format:0,
like_num:0,
is_from_friend:0,
is_from_me:1,
my_id:e.my_id,
content_id:e.content_id,
reply_new:{
reply_list:[]
}
};
at(O.mylistContainer),at(O.mylistFooter),J.myList.add({
data:[i],
mode:"unshift"
}),yt(),"function"==typeof o&&o();
break;

case-6:
window.weui.alert("你留言的太频繁了，休息一下吧");
break;

case-7:
window.weui.alert("你还未关注该公众号，不能参与留言");
break;

case-10:
window.weui.alert("字数不能多于600个");
break;

case-15:
window.weui.alert("留言已关闭");
break;

case-18:
window.weui.alert("你在此文章的留言次数已达上限");
break;

default:
z=t,window.weui.alert("系统错误，请重试");
}
0!==Number(e.ret)&&lt(J.reportData.addCommentErr,"type:resperr;url:"+encodeURIComponent(m)+";ret="+e.ret);
},
error:function(e){
console.log(e),lt(J.reportData.addCommentErr,"type:ajaxerr;url:"+encodeURIComponent(m));
},
complete:s
});
},jt=function(){
var e=K.getSubmit(),t=K.getInput();
if(e.disabled!==!0){
var n=bt($?K.value:t.value),o=n.valid,i=n.content;
o&&(e.disabled=!0,ht({
content:i,
successBegin:function(){
!$&&K.hideEmotionPannel();
},
successEnd:function(){
$?(K.hide(),at(O.inputPC)):t.value="";
},
complete:function(){
""!==t.value&&(e.disabled=!1);
}
}));
}
},vt=function(){
var e=i.join("/mp/appmsg_comment",{
action:"getmycomment",
scene:J.reportData.scene,
appmsgid:window.appmsgid,
idx:window.idx,
comment_id:J.commentId
},!0);
0===H&&(H=1,Array.prototype.forEach.call(O.myCmtLoading,at),c({
url:e,
dataType:"json",
success:function(t){
var n=t.base_resp&&t.base_resp.ret;
if(0===n){
H=2;
var o=t.my_comment;
o&&o.length&&(at(O.mylistContainer),at(O.mylistFooter),J.myList.render(o),J.myList.getIsOversize()&&at(O.mylistFolder)),
q=!0,gt(!0,!1);
}else H=0,lt(J.reportData.errComment,"type:resperr;url:"+encodeURIComponent(e)+";ret="+n);
},
error:function(){
H=0,lt(J.reportData.errComment,"type:ajaxerr;url:"+encodeURIComponent(e));
},
complete:function(){
Array.prototype.forEach.call(O.myCmtLoading,ct);
}
}));
},kt=function(){
var e="discuss_form_editing";
return{
enterEditing:function(){
V=!0,C.canUseCancel&&(O.addBtn.classList.add(e),O.cmtWritePlaceholder.innerHTML="正在输入...");
},
leaveEditing:function(){
V&&(V=!1,C.canUseCancel&&(O.addBtn.classList.remove(e),O.cmtWritePlaceholder.innerHTML="写下你的留言",
y.isAndroid&&(document.body.style.marginBottom="0px")));
}
};
}(),Lt=kt.enterEditing,Dt=kt.leaveEditing,Rt=function At(){
switch(mt){
case 2:
Lt(),C.show({
mask:!0,
disableScroll:!0,
text:G,
placeholder:"留言",
maxLength:600,
showRemindWordCount:10,
disableScrollAdjustment:!1,
scrollContentY:w.getScrollTop()+O.cmtWrite.getBoundingClientRect().top+87,
success:function(e){
Dt();
var t=bt(e),n=t.valid,o=t.content;
n&&ht({
content:o,
successEnd:function(){
G="";
}
});
},
cancel:function(e){
Dt(),G=e;
},
fail:function(){
mt=1,At();
}
});
break;

case 1:
s.invoke("handleMPPageAction",{
action:"writeComment",
title:st,
comment_id:J.commentId,
style:"white"
});
}
return mt;
},xt=function(e){
P=!0,B=m.getScrollTop(),!$&&ct(O.article),J.myList.changeContainer(O.mylistOld),
yt(),at(O.mine),document.body.classList[J.myList.count?"remove":"add"](tt),window.__second_open__&&o.os.ios&&at(O.fakebar),
window.scrollTo(0,0),vt(),!e&&setTimeout(function(){
return K.focus();
},3);
},Tt=function(){
P=!1,J.myList.changeContainer(O.mylist),ct(O.mine),at(O.article),window.scrollTo(0,B),
K.blur(),document.body.classList.remove(et),document.body.classList.remove(tt);
},Ft=function(t,n){
if(1*window.item_show_type===5){
var i=e("pages_new/common_share/video/store.js");
i.dispatch("mp-video-player/auto-next-plugin/cancelAutoNextWhenTipsShowed",6);
}
switch(t&&t.preventDefault(),Rt()){
case 2:
g.report(19048,_extends({
EventType:1,
IsFans:J.isFans,
CommentPageType:3
},F));
break;

case 1:
g.report(19048,_extends({
EventType:1,
IsFans:J.isFans,
CommentPageType:2
},F));
break;

case 0:
default:
if(m.isNativePage()||document.body.classList.add(et),n)return it&&console.log("FakeHash on comment"),
void xt();
t.preventDefault(),window.__second_open__&&o.os.ios?xt():(it&&console.log("push comment"),
r.push("comment")),g.report(19048,_extends({
EventType:1,
IsFans:J.isFans,
CommentPageType:1
},F));
}
},St=function(){
a.tap(O.mylistFolder,yt),a.on(window,"scroll",wt),a.on(window,"scroll",pt),a.bindVisibilityChangeEvt(function(e){
e&&!dt(O.cmtContainer)&&Ct({
notFirstRender:!0,
forceRefresh:!0,
cb:It
});
});
var e=function t(){
O.mylistFolder?dt(O.mylistFolder)&&(g.report(19462,_extends({
CommentId:parseInt(J.commentId,10)||0,
actiontype:1,
wording:"展开全部留言",
number:J.myList.count,
devicetype:1
},S)),a.off(window,"scroll",t)):a.off(window,"scroll",t);
};
if(a.on(window,"scroll",e),e(),m.bindDebounceScrollEvent(_t),$)a.tap(O.inputPC,function(){
ct(O.inputPC),K.show(O.inputPC);
});else switch(a.tap(O.cmtWrite,Ft),mt){
case 2:
y.isAndroid&&C.canUseCancel&&C.onGetKeyboardHeight(function(e){
if(V){
var t=e+55,n=R-O.cmtWrite.getBoundingClientRect().top-t,o={
y:m.getScrollTop()-n
};
Math.abs(n)<150?o.speed=300:o.duration=.3,document.body.style.marginBottom=t+"px",
v(o);
}
});
break;

case 1:
m.listenMpPageAction(function(e){
"deleteComment"===e.action&&J.cmtList.remove({
myId:e.personal_comment_id
}),"deleteCommentReply"===e.action&&J.cmtList.remove({
type:"reply",
myId:e.personal_comment_id,
replyId:e.replyId
}),"praiseComment"===e.action&&(e.reply_id&&0!==e.reply_id?(J.cmtList.setLikeInfo({
type:"reply",
myId:e.personal_comment_id,
replyId:e.reply_id,
likeStatus:e.is_like
}),J.cmtDialog.setReplyLikeInfo({
myId:e.personal_comment_id,
replyId:e.reply_id,
likeStatus:e.is_like
})):J.cmtList.setLikeInfo({
myId:e.personal_comment_id,
likeStatus:e.is_like
}));
});
break;

case 0:
O.goback&&a.on(O.goback,"click",function(e){
e.preventDefault(),Tt(),ct(O.fakebar);
}),o.os.ios&&window.__second_open__&&!function(){
var e=null,t=null;
a.on(window,"orientationchange",function(){
"none"!==O.fakebar.style.display&&(clearTimeout(e),e=setTimeout(function(){
window.innerWidth!==parseFloat(getComputedStyle(O.fakebar).width)&&(clearTimeout(t),
O.mine.style.height=R+"px",window.scrollBy&&window.scrollBy(0,1),t=setTimeout(function(){
window.scrollBy&&window.scrollBy(0,-1),O.mine.style.height="";
},100));
},50));
});
}();
}
},Pt=function(e){
if(J.canC2CReply=0!==(256&e.test_flag),J.onlyFansCanComment=e.only_fans_can_comment,
J.nickName=e.nick_name,J.isFans=e.is_fans,J.headImg=e.logo_url,J.commentCount=e.comment_count,
J.onlyFansDaysCanComment=e.only_fans_days_can_comment,J.isFansDays=e.is_fans_days,
window._has_comment=!0,console.log("inwechat",nt,"commentid",J.commentId),!nt||0===Number(J.commentId))return void(window._has_comment=!1);
var t=w.getId("js_cmt_container");
ot&&(t.insertAdjacentHTML("afterbegin",d.tmpl(_,{
deviceIsPc:$
})),ot.innerHTML=d.tmpl(p,{
isWxWork:Z
})),$?document.body.classList.add("pages_skin_pc"):0===mt&&document.body.insertAdjacentHTML("beforeend",d.tmpl(u,{
textPageTitle:1*window.item_show_type===10?w.getId("js_text_content").innerHTML.replace(/<(\/?)(?=((a(\s|>))|(\/a))).*?>/g,""):window.msg_title.html(1)
},!1));
var n=w.getId("js_cmt_write");
O={
article:w.getId("js_article"),
mine:w.getId("js_cmt_mine"),
main:w.getId("js_cmt_main"),
input:w.getId("js_cmt_input"),
goback:w.getId("js_cmt_goback"),
list:w.getId("js_cmt_list"),
mylistContainer:w.getId("js_my_list_container"),
mylist:w.getId("js_my_list"),
mylistFolder:w.getId("js_my_list_folder"),
mylistFooter:w.getId("js_my_list_footer"),
mylistOld:w.getId("js_my_list_old"),
morelist:w.getId("js_cmt_morelist"),
loading:w.getId("js_cmt_loading"),
fakebar:w.getId("js_fake_bar"),
statement:w.getId("js_cmt_statement"),
myCmtLoading:w.qsAll(".js_mycmt_loading"),
cmtWrite:n,
cmtWritePlaceholder:w.qs(".js_cmt_write_placeholder",n),
cmtContainer:t,
commentPC:w.getId("js_comment_pc"),
inputPC:w.getId("js_cmt_input_pc"),
containerPC:w.getId("js_cmt_container_pc"),
addbtnPC:w.getId("js_cmt_addbtn_pc"),
emotionSwitchPC:w.getId("js_emotion_wrp_pc"),
inputHolder:w.getId("js_cmt_input_holder"),
addBtn:w.getId("js_cmt_addbtn"),
updateDialog:w.getId("js_update_dialog"),
updateCancel:w.getId("js_update_cancel"),
updateConfirm:w.getId("js_update_confirm"),
deleteReplyPanel:w.getId("js_delete_reply_panel"),
deleteReplyConfirm:w.getId("js_delete_reply_confirm"),
deleteReplyCancel:w.getId("js_delete_reply_cancel"),
cmtDialog:w.getId("js_cmt_dialog")
},J.cmtDialog=new h({
globalData:J,
canAddComment:D,
onGetReplyList:function(e,t){
t.filter(function(e){
return 2===e.is_from;
}).forEach(function(t){
J.cmtList.setLikeInfo({
type:"reply",
contentId:e,
replyId:t.reply_id,
likeStatus:t.reply_like_status,
likeNum:t.reply_like_num
});
});
}
}),J.cmtList=new b({
globalData:J,
container:O.list,
type:"elected",
canAddComment:D,
onPraise:function(e,t,n,o,i){
!J.canC2CReply&&J.myList.setLikeInfo({
type:e,
contentId:t,
replyId:n,
likeStatus:o,
likeNum:i
}),J.cmtDialog.setReplyLikeInfo({
contentId:t,
replyId:n,
likeStatus:o,
likeNum:i
});
},
onRender:function(){
_t();
},
onAdd:function(e,t,n,o,i){
!J.canC2CReply&&J.myList.add({
data:e,
mode:t,
type:n,
contentId:o,
pos:i
}),_t();
},
onRemove:function(e,t,n){
!J.canC2CReply&&J.myList.remove({
type:e,
contentId:t,
replyId:n.reply_id
}),_t();
},
onEmpty:function(e){
"comment"===e&&(ct(O.main),ct(O.statement));
},
beforeShowKeyboard:function(){
Dt();
}
}),J.myList=new b({
globalData:J,
container:O.mylist,
type:"mine",
canAddComment:D,
onPraise:function(e,t,n,o,i){
!J.canC2CReply&&J.cmtList.setLikeInfo({
type:e,
contentId:t,
replyId:n,
likeStatus:o,
likeNum:i
});
},
onRender:function(){
_t();
},
onAdd:function(e,t,n,o,i){
!J.canC2CReply&&"reply"===n&&J.cmtList.add({
data:e,
mode:t,
type:n,
contentId:o,
pos:i
}),_t(),yt();
},
onRemove:function(e,t,n){
O.mylistFolder&&J.myList.showTopItems()&&yt(),!J.canC2CReply&&J.cmtList.remove({
type:e,
contentId:t,
replyId:n.reply_id
}),_t();
},
onEmpty:function(){
ct(O.mylistContainer),ct(O.mylistFooter),P&&document.body.classList.add(tt);
},
beforeShowKeyboard:function(){
Dt();
}
}),window.cl=J.cmtList,window.ml=J.myList,0===mt&&window.__second_open__&&o.os.ios&&(O.mine.style.marginBottom=getComputedStyle(O.fakebar).height),
!e.notAutoGetComment&&Ct({
forceRefresh:!0,
cb:It
}),"1"===i.getQuery("js_my_comment")&&(1===mt?Rt():0!==mt||$||xt(!0)),vt(),St(),
$?K=new j({
placeholder:"留言被公众号精选后，将对所有人可见",
submitText:"留言",
length:600,
onSubmit:jt,
onHide:function(){
at(O.inputPC);
}
}):0===mt&&(K=new j({
placeholder:"留言被公众号精选后，将对所有人可见",
submitText:"留言",
length:600,
onSubmit:jt,
onClick:function(){
window.__second_open__&&ct(O.fakebar);
},
onBlur:function(){
"none"!==O.mine.style.display&&at(O.fakebar);
}
}),K.show(w.getId("js_comment_input_old"),{
renderType:"append"
}));
},zt=function(){
$||0!==mt||(r.on("comment",function(){
Ft(null,!0);
}),r.on("article",function(){
it&&console.log("FakeHash on article"),Tt();
}),r.on(function(e){
"comment"===e&&Tt();
}));
};
return zt(),{
initComment:Pt,
getCommentData:Ct,
renderComment:It
};
});define("appmsg/like_and_share.js",["biz_common/dom/event.js","biz_common/dom/class.js","biz_wap/jsapi/core.js","pages/utils.js","appmsg/retry_ajax.js","appmsg/set_font_size.js","common/comm_report.js","appmsg/related_article.js","common/utils.js","biz_wap/utils/device.js","biz_wap/utils/mmversion.js","appmsg/appmsg_report.js"],function(e,i,o,n){
"use strict";
var t=e("biz_common/dom/event.js"),s=e("biz_common/dom/class.js"),r=e("biz_wap/jsapi/core.js"),m=e("pages/utils.js"),a=m.formatReadNum,l=e("appmsg/retry_ajax.js"),d=e("appmsg/set_font_size.js"),p=e("common/comm_report.js"),w=e("appmsg/related_article.js"),c=e("common/utils.js"),_=e("biz_wap/utils/device.js"),u=e("biz_wap/utils/mmversion.js"),k=e("appmsg/appmsg_report.js"),g=function(e){
return document.getElementById(e);
},h=function(e){
e.style.display="block";
},j={
likeNum:0,
isLike:0,
likeDom:g("like_old"),
likeNumDom:g("likeNum_old"),
shareDom:g("js_bottom_share"),
collectDom:g("js_bottom_collect"),
oprRightDom:g("js_bottom_opr_right"),
shareBottomBtn:g("js_bottom_share_btn"),
likeBottomBtn:g("js_bottom_zan_btn"),
similarZanCard:g("js_similar_video_card"),
overflowFontScale:1
},f=function(){
var e=0;
try{
e=1*window.atob(window.biz);
}catch(i){}
var o={
BizUin:e,
BizUinStr:window.biz||"",
AppMsgId:window.parseInt(window.mid,10)||0,
ItemIdx:window.parseInt(window.idx,10)||0,
ItemShowType:window.parseInt(window.item_show_type,10)||0,
SessionIdStr:window.sessionid||"",
EnterId:window.parseInt(window.enterid,10)||0,
Scene:window.parseInt(window.source,10)||0,
SubScene:window.parseInt(window.subscene,10)||0,
EventType:4
};
p.report(19048,o);
},v=function(){
setTimeout(function(){
s.removeClass(j.oprRightDom,"sns_opr_overflow");
var e=j.oprRightDom.querySelectorAll(".js_media_tool_meta"),i=g("js_toobar3").getBoundingClientRect().width,o=0;
if(e&&e.length){
g("js_like_wording").textContent="在看",g("js_parise_wording").textContent="赞";
for(var n=0;n<e.length;n++)o+=e[n].getBoundingClientRect().width;
if(console.log("benchmarkWidth",i,o),e.length>1&&(i-o)/(e.length-1)<20){
g("js_like_wording").textContent="",g("js_parise_wording").textContent="";
for(var t=0,n=0;n<e.length;n++)t+=e[n].getBoundingClientRect().width;
(i-t)/(e.length-1)<20&&s.addClass(j.oprRightDom,"sns_opr_overflow");
}
}
},50);
},D=function(){
s.addClass(j.likeDom,"praised"),j.likeNum++;
var e=j.likeNumDom.innerHTML;
("10万+"!==e||"100k+"!==e)&&(j.likeNumDom.innerHTML=a(j.likeNum)),j.likeNumDom.style.display="",
w&&w.render&&w.render("praise");
},b=function(){
s.removeClass(j.likeDom,"praised"),j.likeNum--;
var e=j.likeNumDom.innerHTML;
j.likeNum>=0&&"10万+"!==e&&"100k+"!==e&&(j.likeNumDom.innerHTML=a(j.likeNum)),0===j.likeNum&&(j.likeNumDom.style.display="none");
},y=[],B=function(e){
"function"==typeof e&&y.push(e);
},N=function(e){
j.isLike=j.isLike?0:1,j.isLike?D():b(),l({
url:"/mp/appmsg_like?__biz="+window.biz+"&mid="+window.mid+"&idx="+window.idx+"&like="+j.isLike+"&f=json&appmsgid="+window.appmsgid+"&itemidx="+window.itemidx,
data:{
scene:window.source,
appmsg_like_type:1,
item_show_type:parseInt(window.item_show_type,10),
client_version:window.clientversion,
is_temp_url:window.is_temp_url||0,
style:e||0,
exptype:window.exptype||"",
expsessionid:window.expsessionid||""
},
type:"POST"
}),y.forEach(function(e){
e(j.isLike,j.likeNum);
});
},z=function(e){
return j.likeBottomBtn&&j.likeBottomBtn.disabled===!0?void 0:window.is_temp_url?void("5"!==window.item_show_type||!c.isNativePage()||_.os.pc?window.weui.alert("预览状态下无法操作"):n("预览状态下无法操作")):void N(e);
};
t.on(j.likeDom,"click",function(){
return z();
}),t.on(j.shareDom,"click",function(){
j.shareBottomBtn&&j.shareBottomBtn.disabled===!0||(f(),r.invoke("handleMPPageAction",{
action:"share"
}));
}),t.on(j.collectDom,"click",function(){
r.invoke("handleMPPageAction",{
action:"doFavorite"
}),w&&w.render&&w.render("favorite"),k.shareReport({
link:window.msg_link||window.cgiData&&window.cgiData.msg_link,
action_type:24,
share_source:2
});
});
var I=function(){
v(),d.onFontScaleChange(v),window.addEventListener("resize",v);
},L=function(e){
var i=e.shareShow,o=e.likeShow,n=e.likeNum,t=e.isLike,r=e.shareGray,m=e.likeGray;
j.likeNum=n,j.isLike=t,i&&j.shareDom&&(_.os.pc?_.os.windows&&u.getInner()>="63010000"&&h(j.shareDom):h(j.shareDom)),
r&&j.shareBottomBtn&&(j.shareBottomBtn.disabled=!0),o&&j.likeDom&&h(j.likeDom),m&&j.likeBottomBtn&&(j.likeBottomBtn.disabled=!0),
o&&j.likeNumDom&&0!==n&&(j.likeNumDom.innerHTML=a(j.likeNum),j.likeNumDom.style.display="",
t&&s.addClass(j.likeDom,"praised")),(u.isWechat&&(_.os.iphone&&u.getInner()>"17001000"||_.os.android&&u.getInner()>"27001300")||_.os.windows&&u.getInner()>="63010000")&&h(j.collectDom),
I(),y.forEach(function(e){
e(j.isLike,j.likeNum);
});
};
return{
initLikeShareDom:L,
triggerLike:z,
onLikeChange:B
};
});define("appmsg/like.js",["biz_common/dom/event.js","biz_common/dom/class.js","biz_wap/utils/ajax.js","biz_common/base64.js","biz_wap/utils/jsmonitor_report.js","appmsg/log.js","complain/tips.js","appmsg/retry_ajax.js","biz_wap/jsapi/core.js","biz_wap/utils/mmversion.js","common/utils.js","appmsg/loading.js","biz_wap/utils/device.js","appmsg/pay_report_utils.js","pages/utils.js","appmsg/related_article.js"],function(require,exports,module,alert){
"use strict";
function qs(e){
return document.getElementById(e);
}
function showAppToast(e,i){
JSAPI.invoke("handleMPPageAction",{
action:"showToast",
wording:e||"",
status:i||"success"
});
}
function initLikeEvent(opt){
function show(e){
e.style.display="";
}
function hide(e){
e.style.display="none";
}
function vShow(e){
e.style.visibility="visible";
}
function vHide(e){
e.style.visibility="hidden";
}
function clear(e){
e.value="";
}
function showLoading(){
commonUtils.isNativePage()?showAppToast("发送中","loading"):Loading.show("发送中");
}
function hideLoading(){
commonUtils.isNativePage()?showAppToast("","dismissloading"):Loading.hide();
}
function showToast(e){
commonUtils.isNativePage()?showAppToast(e):(el_toastMsg.innerHTML=e,show(el_likeToast),
setTimeout(function(){
hide(el_likeToast);
},1e3));
}
function alert2(e){
"5"!==window.item_show_type||!commonUtils.isNativePage()||Device.os.pc?window.weui.alert(e):alert(e);
}
function failAlert(e){
return e&&e.length>maxLikeCommentWord?void alert2("想法不可以超过%s字".replace("%s",maxLikeCommentWord)):void alert2("网络异常，请稍后重试");
}
function isAppCommentAvailable(){
return mmversion.isWechat?Device.os.ipad?!1:mmversion.isInMiniProgram?!1:mmversion.isIOS&&mmversion.gtVersion("7.0.8")?!0:mmversion.isAndroid&&mmversion.gtVersion("7.0.8")?!0:commonUtils.isNativePage()&&(mmversion.isIOS||mmversion.isAndroid)?!0:!1:!1;
}
var scrollTop,el_like=opt.likeAreaDom,el_likeNum=opt.likeNumDom,showType=opt.showType,prompted=opt.prompted,haokanLock=!1,startY,jumpWowLock=!1,el_likeToast=qs("js_like_toast"),el_likeBtn=qs("js_like_btn"),el_toastMsg=qs("js_toast_msg"),el_likeEducate=qs("js_like_educate"),el_friend_like=qs("js_friend_like_area"),el_go_wow=qs("js_go_wow"),el_likeComment=qs("js_like_comment"),el_bcommentPanel2=qs("js_comment_panel"),el_likeCommentShare=qs("js_like_comment_share"),el_likeCommentText=qs("js_comment_text"),el_commentCancel=qs("js_comment_cancel"),el_commentConfirm=qs("js_comment_confirm"),el_commentErrorMsg=qs("js_like_comment_msg"),el_commentCurrentCount=qs("js_like_current_cnt"),el_commentArea=qs("js_comment_area"),el_panelLikeTitle=qs("js_panel_like_title"),el_wowClosePanel=qs("wow_close_inform"),el_wowCloseAck=qs("wow_close_ack"),el_alertPanel=qs("js_alert_panel"),el_alertContent=qs("js_alert_content"),el_alertConfirm=qs("js_alert_confirm");
if(el_like&&el_likeNum){
window.appmsg_like_type&&2===window.appmsg_like_type?jsmonitorReport.setSum(114217,0,1):window.appmsg_like_type&&1===window.appmsg_like_type&&jsmonitorReport.setSum(114217,1,1);
var like_report=function(){
var e=el_like.getAttribute("like"),i=el_likeNum.innerHTML,t=parseInt(e)?parseInt(e):0,o=t?0:1,n=parseInt(i)?parseInt(i):0,s=opt.appmsgid||opt.mid,l=opt.itemidx||opt.idx;
if(t){
if(1!==appmsg_like_type)return void sendRecommendAjax(0);
Class.removeClass(el_like,opt.className),el_like.setAttribute("like",0),n>0&&"100000+"!==i&&(el_likeNum.innerHTML=n-1==0?"赞":n-1);
}else if(1===appmsg_like_type)el_like.setAttribute("like",1),Class.addClass(el_like,opt.className),
"100000+"!==i&&(el_likeNum.innerHTML=n+1);else if(2===appmsg_like_type)return void initRecommendPanel();
RetryAjax({
url:"/mp/appmsg_like?__biz="+opt.biz+"&mid="+opt.mid+"&idx="+opt.idx+"&like="+o+"&f=json&appmsgid="+s+"&itemidx="+l,
data:{
is_temp_url:opt.is_temp_url||0,
scene:window.source,
subscene:window.subscene,
appmsg_like_type:window.appmsg_like_type,
item_show_type:parseInt(window.item_show_type,10),
client_version:window.clientversion,
action_type:o?1:2,
device_type:window.devicetype,
exptype:window.exptype||"",
expsessionid:window.expsessionid||""
},
type:"POST"
});
},initRecommendPanel=function(){
sendRecommendAjax(1,"",1);
},isBeenUnvisible=function(e){
function i(){
return window.pageYOffset||document.documentElement.scrollTop||document.body.scrollTop||0;
}
return e.offsetTop+el_likeComment.offsetHeight-i()>=commonUtils.getInnerHeight()?!0:!1;
},disableMove=function(){
document.addEventListener("touchmove",preventMove,{
passive:!1
}),el_likeCommentText.addEventListener("touchstart",getTouchStart,{
passive:!1
}),el_likeCommentText.addEventListener("touchmove",preventText,!1);
},enableMove=function(){
document.removeEventListener("touchmove",preventMove,{
passive:!1
}),el_likeCommentText.removeEventListener("touchstart",getTouchStart,{
passive:!1
}),el_likeCommentText.removeEventListener("touchmove",preventText,!1);
},preventMove=function(e){
var i=e.target;
"TEXTAREA"!==i.tagName&&"BUTTON"!==i.tagName&&(e.preventDefault(),e.stopPropagation());
},getTouchStart=function(e){
var i=e.targetTouches||[];
if(i.length>0){
var t=i[0]||{};
startY=t.clientY;
}
},preventText=function(e){
var i=!1,t=e.changedTouches,o=this.scrollTop,n=this.offsetHeight,s=this.scrollHeight;
if(t.length>0){
var l=t[0]||{},a=l.clientY;
i=a>startY&&0>=o?!1:startY>a&&o+n>=s?!1:!0,i||e.preventDefault();
}
},isShow=function(e){
return"none"===e.style.display||"hidden"===e.style.visibility?!1:""===e.style.display||"block"===e.style.display||"visible"===e.style.visibility?!0:void 0;
},validataComment=function(e,i){
var t=e.value.replace(/^\s+|\s+$/g,"");
sendRecommendAjax(1,t,i);
},showEducatePanel=function(e,i,t){
show(el_likeComment);
var o=window.source||window.cgiData&&window.cgiData.source||0;
return o&&(o=parseInt(o,10),94===o)?void(e&&5===e&&hide(el_likeComment)):void(i||(show(el_likeEducate),
t&&t>0&&(el_friend_like.innerHTML="%s位朋友也在看,".replace("%s",t),document.getElementById("js_friend_like_word").innerText="前往“发现”-“看一看”浏览",
show(el_friend_like)),1===showType&&(hide(el_go_wow),hide(el_likeCommentShare)),
isBeenUnvisible(el_likeComment)&&scrollToShow(el_likeComment),educateExpose()));
},setBtnLike=function(){
el_like.setAttribute("like",1),Class.addClass(el_likeBtn,opt.className),realLikeNum+=1;
var e=el_likeNum.innerHTML;
"10万+"!==e&&(el_likeNum.innerHTML=formatReadNum(realLikeNum));
},setLike2Status=function(e,i,t){
var o="在看";
switch(showType){
case 1:
switch(prompted){
case 0:
showEducatePanel(e,i,t),show(el_likeComment),prompted=1;
break;

case 1:
hide(el_likeEducate),showToast(o);
}
setBtnLike();
break;

case 2:
switch(hide(el_bcommentPanel2),clear(el_likeCommentText),prompted){
case 0:
showEducatePanel(e,i,t),5===e&&hide(el_likeCommentShare);
break;

case 1:
(4===e||5===e)&&showToast(4===e?"已发送":o);
}
5!==e&&(4===e&&"none"!==el_likeEducate.style.display?hide(el_likeCommentShare):4===e?hide(el_likeComment):(show(el_commentArea),
show(el_likeCommentShare),1===prompted&&hide(el_likeEducate),show(el_likeComment),
isBeenUnvisible(el_likeComment)&&scrollToShow(el_likeComment))),4!==e&&setBtnLike(),
prompted=1;
}
enableMove(),commonUtils.isNativePage()&&JSAPI.invoke("handleHaokanAction",{
action:"closeComment"
}),log("[Appmsg] zaikan set like success");
},unsetLike2Status=function(e){
1===e?setTimeout(function(){
alert2(" 已取消，想法已同步删除");
},20):showToast("已取消"),2===showType&&isShow(el_likeComment)&&hide(el_likeComment);
var i=el_likeNum.innerHTML;
Class.removeClass(el_likeBtn,opt.className),el_like.setAttribute("like",0),el_likeComment&&hide(el_likeComment),
realLikeNum-=1,realLikeNum>=0&&"10万+"!==i&&(el_likeNum.innerHTML=formatReadNum(realLikeNum)),
log("[Appmsg] zaikan set unlike success");
},sendRecommendAjax=function sendRecommendAjax(like,comment,type,clientType){
if(!haokanLock){
log("[Appmsg] prepare to send appmsg like request"),showLoading();
var appmsgid=opt.appmsgid||opt.mid,itemidx=opt.itemidx||opt.idx;
haokanLock=!0;
var action_type;
like?(window.isPaySubscribe&&payReportUtils.reportPayAppmsg(12),action_type=type):(window.isPaySubscribe&&payReportUtils.reportPayAppmsg(13),
action_type=2),ajax({
url:"/mp/appmsg_like?__biz="+opt.biz+"&mid="+opt.mid+"&idx="+opt.idx+"&like="+like+"&f=json&appmsgid="+appmsgid+"&itemidx="+itemidx,
data:{
is_temp_url:opt.is_temp_url||0,
scene:window.source,
subscene:window.subscene,
appmsg_like_type:window.appmsg_like_type,
item_show_type:parseInt(window.item_show_type,10),
client_version:window.clientversion,
comment:comment?comment:"",
prompted:1,
style:clientType||showType,
action_type:action_type,
passparam:window.passparam,
request_id:(new Date).getTime(),
device_type:window.devicetype,
exptype:window.exptype||"",
expsessionid:window.expsessionid||""
},
type:"POST",
success:function success(res){
haokanLock=!1;
var data=eval("("+res+")");
hideLoading(),log("[Appmsg] success send appmsglike like "+like+" return value is "+JSON.stringify(res)),
0==data.base_resp.ret?(like?(setLike2Status(type,data.is_eu_user,data.friend_like_num),
relatedArticles&&relatedArticles.render&&relatedArticles.render("like")):unsetLike2Status(data.has_comment),
connectWithApp(like,comment,clientType)):failAlert(comment);
},
error:function(){
hideLoading(),failAlert(),haokanLock=!1;
}
});
}
};
JSAPI.on("menu:haokan",function(e){
var i=0===parseInt(e.recommend)?0:1;
if(0===i)sendRecommendAjax(i,"",2,clientShowType);else{
var t="";
t=e.comment;
var o=1===e.scene?4:5;
sendRecommendAjax(i,t,o,clientShowType);
}
});
var connectWithApp=function(e,i){
var t={
origin:"mp",
isLike:e?1:0,
url:encodeURIComponent(msg_link.html(!1)),
content:i?i:""
};
JSAPI.invoke("handleHaokanAction",{
action:actionString,
recommend:e?1:0,
server_data:JSON.stringify(t)
},function(e){
console.log("handleHaokanAction",e);
}),JSAPI.invoke("handleHaokanAction",{
action:actionForClient,
permission:1,
recommend:e?1:0
},function(e){
console.log("handleHaokanAction for client",e);
});
},goWoW=function(){
jumpWowLock||(jumpToWowClickReport(),jumpWowLock=!0,JSAPI.invoke("handleHaokanAction",{
action:"jumpToWow",
extParams:JSON.stringify({
autoDropLoad:!0
})
},function(e){
jumpWowLock=!1,console.log("jumpToWow",e),e.err_msg&&"handleHaokanAction:fail_entrance_not_open"===e.err_msg?show(el_wowClosePanel):"handleHaokanAction:fail  action not support"===e.err_msg||"handleHaokanAction:fail, action not support"===e.err_msg?alert2("微信版本过低，暂不支持该操作"):"handleHaokanAction:ok"===e.err_msg&&hide(el_likeComment),
JSAPI.invoke("handleHaokanAction",{
action:actionString,
server_data:JSON.stringify({
origin:"mp",
autoDropLoad:!0
})
},function(e){
console.log("sendAutoDropLoad",e);
});
}));
},likeClickReport=function(){
ajax({
url:"/mp/appmsgreport?action=appmsglikeclickcomment&__biz="+opt.biz+"&mid="+opt.mid+"&idx="+opt.idx+"&f=json&appmsgid="+appmsgid+"&itemidx="+itemidx,
data:{
is_temp_url:opt.is_temp_url||0,
scene:window.source,
subscene:window.subscene,
appmsg_like_type:window.appmsg_like_type,
item_show_type:parseInt(window.item_show_type,10),
client_version:window.clientversion,
device_type:window.devicetype
},
type:"POST"
});
},likeExpose=function e(){
var i=document.documentElement.scrollTop||window.pageYOffset||document.body.scrollTop,t=qs("like3").offsetTop,o=opt.appmsgid||opt.mid,n=opt.itemidx||opt.idx;
i+commonUtils.getInnerHeight()>t&&t>=i&&(ajax({
url:"/mp/appmsgreport?action=appmsglikeexposure&__biz="+opt.biz+"&mid="+opt.mid+"&idx="+opt.idx+"&f=json&appmsgid="+o+"&itemidx="+n,
data:{
is_temp_url:opt.is_temp_url||0,
scene:window.source,
subscene:window.subscene,
appmsg_like_type:window.appmsg_like_type,
item_show_type:parseInt(window.item_show_type,10),
client_version:window.clientversion,
device_type:window.devicetype
},
type:"POST"
}),DomEvent.off(window,"scroll",e));
},educateExpose=function i(){
var e=(document.documentElement.scrollTop||window.pageYOffset||document.body.scrollTop,
opt.appmsgid||opt.mid),t=opt.itemidx||opt.idx,o=window.item_show_type,n=window.enterid||window.cgiData&&window.cgiData.enterid||"";
el_likeEducate&&"none"!=el_likeEducate.style.display&&commonUtils.getInnerHeight()>el_likeEducate.getBoundingClientRect().top&&el_likeEducate.getBoundingClientRect().top+el_likeEducate.getBoundingClientRect().height>0&&(ajax({
url:"/mp/webcommreport?action=report&report_useruin=1&__biz="+window.biz,
type:"POST",
data:{
logid:18266,
buffer:["",Base64.decode(opt.biz),e,t,window.source,window.subscene,1,o,sessionid,n]
},
async:!1,
timeout:2e3
}),DomEvent.off(window,"scroll",i));
},jumpToWowClickReport=function(){
var e=opt.appmsgid||opt.mid,i=opt.itemidx||opt.idx,t=window.enterid||window.cgiData&&window.cgiData.enterid||"";
ajax({
url:"/mp/webcommreport?action=report&report_useruin=1&__biz="+window.biz,
type:"POST",
data:{
logid:18266,
buffer:["",Base64.decode(opt.biz),e,i,window.source,window.subscene,2,window.item_show_type,sessionid,t]
},
async:!1,
timeout:2e3
});
};
DomEvent.on(el_alertConfirm,"click",function(){
el_alertPanel.style.display="none";
}),DomEvent.on(el_like,"click",function(e){
if(el_likeBtn.disabled!==!0){
if(window.is_temp_url)return void alert2("预览状态下无法操作");
var i=el_like.getBoundingClientRect();
return log("[Appmsg zaikan location] top: "+i.top+" left: "+i.left+" bottom: "+i.bottom+" right: "+i.right),
log("[Appmsg zaikan click] clientX: "+e.clientX+" clientY: "+e.clientY),e.currentTarget.classList.contains("js_disabled")?!1:(like_report(e),
!1);
}
}),DomEvent.on(el_wowCloseAck,"click",function(){
hide(el_wowClosePanel);
}),DomEvent.on(qs("js_mask_2"),"mousedown",function(){
hide(el_bcommentPanel2),clear(el_likeCommentText),vHide(el_commentErrorMsg),enableMove();
}),DomEvent.on(el_commentConfirm,"mousedown",function(){
validataComment(el_likeCommentText,4);
}),DomEvent.on(el_commentCancel,"mousedown",function(){
hide(el_bcommentPanel2),clear(el_likeCommentText),vHide(el_commentErrorMsg),enableMove();
}),DomEvent.on(el_likeCommentShare,"click",function(){
return commonUtils.isNativePage()?void JSAPI.invoke("handleHaokanAction",{
action:"writeComment",
style:"white"
}):(scrollTop=document.body.scrollTop||document.documentElement.scrollTop,1*window.item_show_type===10&&(el_panelLikeTitle.innerHTML=window.msg_title.replace(/<(\/?)(?=((a(\s|>))|(\/a))).*?>/g,"")),
show(el_bcommentPanel2),el_likeCommentText.focus(),el_commentConfirm.setAttribute("disabled","disabled"),
disableMove(),void likeClickReport());
}),DomEvent.on(el_likeCommentText,"focus",function(){}),DomEvent.on(el_likeCommentText,"blur",function(){
window.scrollTo(0,scrollTop);
}),DomEvent.on(window,"scroll",likeExpose),DomEvent.on(window,"scroll",educateExpose),
DomEvent.on(el_go_wow,"click",goWoW);
var scrollToShow=function(e){
e.scrollIntoView(!1);
};
DomEvent.on(el_likeCommentText,"input",function(e){
var i=el_likeCommentText.value.replace(/^\s+|\s+$/g,"");
i.length>maxLikeCommentWord?(el_commentCurrentCount.innerHTML=i.length,vShow(el_commentErrorMsg)):vHide(el_commentErrorMsg),
i.length>0&&i.length<=maxLikeCommentWord?el_commentConfirm.removeAttribute("disabled"):el_commentConfirm.setAttribute("disabled","disabled"),
Device.os.ios&&e.data&&doubleInputChar.indexOf(e.data)>-1&&(focusTag=!0);
}),DomEvent.on(el_likeCommentText,"click",function(){
Device.os.ios&&focusTag&&(el_likeCommentText.blur(),el_likeCommentText.focus(),focusTag=!1);
});
}
}
function showLikeNum(e){
var i=e||{};
if(i.show){
var t=i.likeAreaDom,o=i.likeNumDom,n=document.getElementById("js_like_btn");
t&&(t.style.display=i.likeAreaDisplayValue,t.style.visibility="",i.liked&&(1===appmsg_like_type?Class.addClass(t,i.className):Class.addClass(n,i.className)),
t.setAttribute("like",i.liked?"1":"0"),i.likeGray&&(n.disabled=!0));
var s=1===appmsg_like_type?"赞":"";
realLikeNum=i.likeNum||s,1===appmsg_like_type?(parseInt(realLikeNum)>1e5?realLikeNum="100000+":"",
o&&(o.innerHTML=realLikeNum)):2===appmsg_like_type&&(o.innerHTML=formatReadNum(realLikeNum));
}
}
var DomEvent=require("biz_common/dom/event.js"),Class=require("biz_common/dom/class.js"),ajax=require("biz_wap/utils/ajax.js"),Base64=require("biz_common/base64.js"),jsmonitorReport=require("biz_wap/utils/jsmonitor_report.js"),log=require("appmsg/log.js"),Tips=require("complain/tips.js"),RetryAjax=require("appmsg/retry_ajax.js"),JSAPI=require("biz_wap/jsapi/core.js"),actionString="submitMsgToTL",actionForClient="update_recommend_status",mmversion=require("biz_wap/utils/mmversion.js"),commonUtils=require("common/utils.js"),Loading=require("appmsg/loading.js"),realLikeNum,clientShowType=5,Device=require("biz_wap/utils/device.js"),payReportUtils=require("appmsg/pay_report_utils.js"),_require=require("pages/utils.js"),formatReadNum=_require.formatReadNum,relatedArticles=require("appmsg/related_article.js"),maxLikeCommentWord=200,focusTag=!1,doubleInputChar=["“”","‘’","（）","《》","〈〉","「」","『』","〔〕","【】","［］","[]","｛｝","{}","()","<>"];
return{
initLikeEvent:initLikeEvent,
showLikeNum:showLikeNum
};
});define("appmsg/read.js",["pages/utils.js","biz_wap/utils/device.js"],function(e){
"use strict";
function i(e){
var i=e||{},n=1586325600,d="undefined"!=typeof window.ct?parseInt(window.ct,10):0;
if(i.show){
var s=i.readAreaDom,o=i.readNumDom;
s&&(s.style.display=i.readAreaDisplayValue);
var r=i.readNum||1,w=window.ori_send_time||window.cgiData&&window.cgiData.ori_send_time||0,p=/(WindowsNT)|(Windows NT)|(Macintosh)/i.test(navigator.userAgent),m=1566025200,u=1565971200,_=a.os.ios||p?m:u;
parseInt(w,10)>_&&window.item_show_type&&"5"===window.item_show_type&&(n>d?("en"!==window.LANG&&(document.getElementById("readTxt").innerText="播放"),
r=i.videouv||0):("en"!==window.LANG&&(document.getElementById("readTxt").innerText="观看"),
r=i.readNum||0)),1===window.appmsg_like_type?(parseInt(r,10)>1e5?r="100000+":"",
o&&(o.innerHTML=r)):2===window.appmsg_like_type&&(o.innerHTML=t(r),""===o.innerHTML&&(o.innerHTML="0"));
}
}
var n=e("pages/utils.js"),t=n.formatReadNum,a=e("biz_wap/utils/device.js");
return{
showReadNum:i
};
});define("appmsg/share_tpl.html.js",[],function(){
return'<div class="rich_media_extra">\n    <a href="<#= url #>" class="share_appmsg_container appmsg_card_context flex_context">\n        <div class="flex_hd">\n            <i class="share_appmsg_icon"> </i>\n        </div>\n        <div class="flex_bd">\n            <div class="share_appmsg_title">分享给订阅用户</div>\n            <p class="share_appmsg_desc">可快速分享原创文章给你的公众号订阅用户</p>\n        </div>\n    </a>\n</div>\n';
});define("appmsg/appmsgext.js",["appmsg/log.js","biz_wap/utils/ajax.js","rt/appmsg/getappmsgext.rt.js","biz_common/utils/wxgspeedsdk.js","biz_common/utils/url/parse.js"],function(e){
"use strict";
function i(e){
var i={
biz:"",
appmsg_type:"",
mid:"",
sn:"",
album_id:"",
idx:"",
scene:"",
title:"",
ct:"",
abtest_cookie:"",
devicetype:"",
version:"",
is_need_ticket:0,
is_need_ad:0,
comment_id:"",
is_need_reward:0,
both_ad:0,
reward_uin_count:0,
send_time:"",
msg_daily_idx:"",
is_original:0,
is_only_read:0,
req_id:"",
pass_ticket:"",
is_temp_url:0,
more_read_type:0,
rtId:"",
rtKey:"",
appmsg_like_type:1,
related_video_sn:"",
vid:"",
is_pay_subscribe:0,
pay_subscribe_uin_count:0,
has_red_packet_cover:0,
related_video_num:e.isPublicRelatedVideo?10:5,
album_video_num:5,
onSuccess:function(){},
onError:function(){}
};
for(var o in e)e.hasOwnProperty(o)&&(i[o]=e[o]);
console.info("[(评论、点赞、赞赏) 发送请求]: ",new Date),t({
url:"/mp/getappmsgext?f=json&mock="+n.getQuery("mock"),
data:{
r:Math.random(),
__biz:i.biz,
appmsg_type:i.appmsg_type,
mid:i.mid,
sn:i.sn,
idx:i.idx,
scene:i.scene,
title:encodeURIComponent(i.title.htmlDecode()),
ct:i.ct,
abtest_cookie:i.abtest_cookie,
devicetype:i.devicetype.htmlDecode(),
version:i.version.htmlDecode(),
is_need_ticket:i.is_need_ticket,
is_need_ad:i.is_need_ad,
comment_id:i.comment_id,
is_need_reward:i.is_need_reward,
both_ad:i.both_ad,
reward_uin_count:i.is_need_reward?i.reward_uin_count:0,
send_time:i.send_time,
msg_daily_idx:i.msg_daily_idx,
is_original:i.is_original,
is_only_read:i.is_only_read,
req_id:i.req_id,
pass_ticket:i.pass_ticket,
is_temp_url:i.is_temp_url,
item_show_type:i.item_show_type,
tmp_version:1,
more_read_type:i.more_read_type,
appmsg_like_type:i.appmsg_like_type,
related_video_sn:i.related_video_sn,
related_video_num:i.related_video_num,
vid:i.vid,
is_pay_subscribe:i.is_pay_subscribe,
pay_subscribe_uin_count:i.pay_subscribe_uin_count,
has_red_packet_cover:i.has_red_packet_cover,
album_id:0x11fd1c7c75070000,
album_video_num:i.album_video_num,
cur_album_id:window.appmsg_album_info?window.appmsg_album_info.id:"",
is_public_related_video:i.isPublicRelatedVideo,
encode_info_by_base64:i.encodeInfoByBase64
},
type:"POST",
dataType:"json",
rtId:i.rtId,
rtKey:i.rtKey,
rtDesc:_,
async:!0,
success:function(e){
if(console.info("[(评论、点赞、赞赏) 响应请求]: ",new Date,e),s("[Appmsg] success get async data"),
"function"==typeof i.onSuccess&&i.onSuccess(e),e)try{
s("[Appmsg] success get async data, async data is: "+JSON.stringify(e));
}catch(t){}else s("[Appmsg] success get async data, async data is empty");
if(!d&&"5"===window.item_show_type){
var _=Date.now()-window.logs.pagetime.page_begin;
if(d=!0,Math.random()>.1)return;
a.saveSpeeds({
uin:window.uin,
pid:675,
speeds:[{
sid:29,
time:_
}]
}),a.send();
}
},
error:function(){
s("[Appmsg] error get async data, biz="+i.biz+", mid="+i.mid),"function"==typeof i.onError&&i.onError();
},
complete:function(){
"function"==typeof i.onComplete&&i.onComplete();
}
});
}
var s=e("appmsg/log.js"),t=e("biz_wap/utils/ajax.js"),_=e("rt/appmsg/getappmsgext.rt.js"),a=e("biz_common/utils/wxgspeedsdk.js"),n=e("biz_common/utils/url/parse.js"),d=void 0;
return{
getData:i
};
});