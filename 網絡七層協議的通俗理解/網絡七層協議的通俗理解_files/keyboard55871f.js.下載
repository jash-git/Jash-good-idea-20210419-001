var _extends=Object.assign||function(e){
for(var a=1;a<arguments.length;a++){
var i=arguments[a];
for(var t in i)Object.prototype.hasOwnProperty.call(i,t)&&(e[t]=i[t]);
}
return e;
};
define("appmsg/without_iframe/video_plugin/video_tail.js",["biz_wap/jsapi/core.js","common/utils.js","biz_wap/utils/device.js","common/comm_report.js","pages/video_plugin/base.js","appmsg/without_iframe/video_plugin/video_tail_utils.js","pages/video_collection/report.js","appmsg/like_and_share.js","pages/video_collection/weapp_channel.js"],function(e){
"use strict";
function a(e,a){
e&&e.contentWindow&&e.contentWindow.postMessage(a,location.origin||"*");
}
function i(e){
this._g={
hasInit:0,
tailIframe:null,
status:"init",
opt:e
},this.videoTailUtils=o();
}
var t=e("biz_wap/jsapi/core.js"),l=e("common/utils.js"),r=e("biz_wap/utils/device.js"),n=e("common/comm_report.js"),s=e("pages/video_plugin/base.js"),o=e("appmsg/without_iframe/video_plugin/video_tail_utils.js"),d=e("pages/video_collection/report.js"),p=e("appmsg/like_and_share.js"),g=e("pages/video_collection/weapp_channel.js");
return s.inherit(i,s.Class),i.prototype.playerReadyHandler=function(){
this.__initVideoTail();
},i.prototype.fullscreenchangeHandler=function(e,i){
if(1===this._g.hasInit){
var t=_extends({},i);
if(r.os.android&&this.player._g.myPlayer&&this.player._g.myPlayer.opt.width<=this.player._g.myPlayer.opt.height)if(i.state){
var l=this.player._g.myPlayer.getWcSlPlayerAndroidSafeAreaInsets();
t.padding=l.top+"px 0 0 0";
}else t.padding="0";
a(this._g.tailIframe,{
hostEnvEvent:"onWcSlPlayerFullscreenChange",
res:t
});
}else i.state?this.videoTailPanel.removeClass("video_screen_half"):this.videoTailPanel.addClass("video_screen_half");
},i.prototype.updateOpt=function(e){
_extends(this._g.opt,e);
},i.prototype.showEndContentHandler=function(){
var e=this;
1===this._g.hasInit?(this._g.tailIframe.style.display="",this.videoTailUtils.sendMPPageData(JSON.stringify({
dataType:"syncLikeStatus",
isLike:this._g.opt.isLike,
likeNum:this._g.opt.likeNum
}),"adWeb"),this.videoTailUtils.sendMPPageData(JSON.stringify({
dataType:"syncTestFlag",
testFlag:this._g.opt.testFlag
}),"adWeb"),a(this._g.tailIframe,{
hostEnvEvent:"onMPAdWebviewStateChange",
res:{
state:"appear"
}
})):this.videoTailUtils.initWebTailPanel(_extends({
replay:function(){
e.player._trigger("replay");
},
fallback:function(){
setTimeout(function(){
e.player._g.myPlayer&&e.player._g.myPlayer.showPlayBtn();
});
}
},this._g.opt));
},i.prototype.__initVideoTail=function(){
var e=this;
this._g.hasInit||(this.videoTailPanel=$("#js_video_tail_panel_"+this._g.opt.vid),
this.videoTailPanel[0].addEventListener("touchmove",function(a){
e.player.isInFullScreen()&&a.preventDefault();
}),this.player._g.myPlayer&&this.player._g.myPlayer._useWcSlPlayer()?!function(){
e._g.hasInit=1,e._g.tailIframe=$('<iframe class="'+e.videoTailPanel.attr("class")+'" style="display:none;padding:0;'+e.videoTailPanel.attr("style")+'" frameborder="no" border="0" scrolling="no"></iframe>')[0],
e.player._g.myPlayer.container.find(".js_page_video").prepend(e._g.tailIframe),e.videoTailUtils.initTailIframe4WcSlPlayer(e._g.tailIframe,e.player._g.myPlayer.id),
e.videoTailPanel.parent().remove(),e.__initWcSlVideoTailListeners();
var a=function t(){
e._g.tailIframe.removeEventListener("load",t),e.fullscreenchangeHandler("fullscreenchange",{
state:e.player.isInFullScreen()
});
};
e._g.tailIframe.addEventListener("load",a);
var i=function l(){
e._g.tailIframe.removeEventListener("error",l),e._g.tailIframe.remove(),e._g.tailIframe=null,
e._g.hasInit=2,e.player._g.myPlayer.container.find(".js_page_video").prepend(e.videoTailPanel.parent()),
e.fullscreenchangeHandler("fullscreenchange",{
state:e.player.isInFullScreen()
}),console.error("[Video Tail Plugin] Failed to init iframe tail, fallback to h5 tail");
};
e._g.tailIframe.addEventListener("error",i);
}():(this._g.hasInit=2,this.player._g.myPlayer&&this.player._g.myPlayer.container.find(".js_page_video").prepend(this.videoTailPanel.parent())));
},i.prototype.__initWcSlVideoTailListeners=function(){
var e=this;
p.onLikeChange(function(a,i){
e._g.opt.isLike=a,e._g.opt.likeNum=i,e.videoTailUtils.sendMPPageData(JSON.stringify({
dataType:"syncLikeStatus",
isLike:a,
likeNum:i
}),"adWeb");
}),this.videoTailUtils.onReceiveMPPageData(function(a){
var i=e.player&&e.player._g.myPlayer;
if("sharePage"===a.data)return void t.invoke("handleMPPageAction",{
action:"share"
});
if("triggerLikeBtn"===a.data)return void p.triggerLike(6);
if("openChannel"===a.data)return void(i.isInFullScreen()?(i.exitFullScreen(),setTimeout(function(){
g.openChannel();
},250)):g.openChannel());
"hasSubscribed"===a.data&&e.videoTailUtils.setTailOpts({
hasSubscribed:!0
});
var l=void 0;
try{
l=JSON.parse(a.data);
}catch(r){
return;
}
"commReport"===l.dataType&&n.report(l.logId,l.logData);
}),window.addEventListener("message",function(i){
var t=void 0;
if(i.origin?t=i.origin:i.originalEvent&&(t=i.originalEvent.origin),/^http(s)?\:\/\/mp\.weixin\.qq\.com$/.test(t)&&i.source){
var r=e.player._g.myPlayer;
if(r&&i.data.__wcSlPlayerLoadTailRelateVideo__)return r.exitFullScreen(),d.leaveReportNowForSwitchVideo(),
void l.loadNewPageKeepingHistoryStackIfSecOpen(i.data.__wcSlPlayerLoadTailRelateVideo__);
if(r&&i.data.__videoTailPlayerId__&&i.data.__videoTailPlayerId__===r.id){
var n=i.data.data;
switch(i.data.action){
case"handleMPPageAction":
var s={
callbackId:i.data.callbackId,
res:{
err_msg:"handleMPPageAction:ok"
}
};
switch(n.action){
case"sendMPPageData":
e.videoTailUtils.emitHostEnvEvent4WcSlPlayer({
data:{
hostEnvEvent:"onReceiveMPPageData",
res:n
}
});
break;

case"opPlayer":
"play"===n.opType&&r.replay();
break;

case"closeAdWebview":
var o=function(){
var a=e._g.tailIframe.getAttribute("class"),i=e._g.tailIframe.getAttribute("style");
e._g.tailIframe.remove(),e._g.tailIframe=$('<iframe class="'+a+'" style="display:none;'+i+'" frameborder="no" border="0" scrolling="no"></iframe>')[0],
e.player._g.myPlayer.container.find(".js_page_video").prepend(e._g.tailIframe),e.videoTailUtils.initTailIframe4WcSlPlayer(e._g.tailIframe,e.player._g.myPlayer.id,!0);
var t=function r(){
e._g.tailIframe.removeEventListener("load",r),e.fullscreenchangeHandler("fullscreenchange",{
state:e.player.isInFullScreen()
});
};
e._g.tailIframe.addEventListener("load",t);
var l=function n(){
e._g.tailIframe.removeEventListener("error",n),e._g.tailIframe.remove(),e._g.tailIframe=null,
e._g.hasInit=2,e.player._g.myPlayer.container.find(".js_page_video").prepend(e.videoTailPanel.parent()),
e.fullscreenchangeHandler("fullscreenchange",{
state:e.player.isInFullScreen()
}),console.error("[Video Tail Plugin] Failed to init iframe tail, fallback to h5 tail");
};
return e._g.tailIframe.addEventListener("error",l),"break";
}();
if("break"===o)break;
}
s.callbackId&&a(e._g.tailIframe,s);
}
}
}
});
},i;
});define("appmsg/without_iframe/video_appmsg.html.js",[],function(){
return'<div id="page-content">\n    <!--S 全屏播放 full_screen_mv-->\n    <div id="js_mpvedio_wrapper_<#=vid#>" style="position:relative; height: <#=video_h#>px">\n        <div class="add_bg_color appmsg_video">\n            <div id="js_video_tail_panel_<#=vid#>" class="video_tail_module video_screen_half" style="display: none;">\n                <div class="video_tail_module__hd" id="js_video_tail_hd">\n                    <div class="account_info_wrp">\n                        <div class="profile_info_wrp js_go_profile">\n                            <img class="account_avatar" src="" alt="" id="js_tail_panel_account_avatar">\n                            <div class="account_name" id="js_tail_panel_account_name"></div>\n                            <div class="subscription_info subscription_success">\n                                <div class="account_subscription_tips js_subscription_success" id="js_subscription_success"\n                                    style="display: none;">已关注</div>\n                                <i class="account_link_icon js_profile_icon" id="js_profile_icon"></i>\n                            </div>\n                        </div>\n                        <div class="btn_account_subscription js_btn_account_subscription" id="js_btn_account_subscription" style="display: none;">\n                            关注</div>\n                    </div>\n                    <div class="opr_wrp">\n                        <span class="opr_item_wrp js_replay" id="js_replay">\n                            <i class="opr_item refresh_icon"></i>\n                            <span class="opr_item_text">重播</span>\n                        </span>\n                        <span class="opr_item_wrp share_item_wrp js_share_button" id="js_tail_share_button"\n                            style="display: none;">\n                            <i class="opr_item share_icon"></i>\n                            <span class="opr_item_text">分享</span>\n                        </span>\n                        <!--点赞后 加className selected-->\n                        <span class="opr_item_wrp like_item_wrp" id="js_tail_like_button" style="display: none;">\n                            <i class="opr_item like_icon"></i>\n                            <span class="opr_item_text">赞</span>\n                        </span>\n                        <span class="opr_item_wrp recommend_item_wrp" id="js_tail_channel_button"\n                            style="display: none;">\n                            <i class="opr_item video-logo_icon"></i>\n                            <span class="opr_item_text">随便看看</span>\n                        </span>\n                    </div>\n                </div>\n\n                <!-- 有拓展内容 -->\n                <div class="have_expand" id="js_expand_area">\n                </div>\n\n                <!-- 广告内容 -->\n                <div class="ad_area" id="js_tail_video_ad_area">\n                </div>\n            </div>\n        </div>\n\n    </div>\n    <!--E 视频播放器-->\n    <!-- S 视频社交-->\n    <div id="bottom_bar" class="interact_video" style="display:none;height: 35px;">\n        <div class="inter_opr">\n            <a id="video_detail_btn" href="javascript:;" target="_blank" class="access_original">\n                视频详情            </a>\n        </div>\n    </div>\n</div>';
});;define('page/appmsg_new/mod/album_read.css', [], function(require, exports, module) {
	return ".wx_icon_pay_tag{color:#fff;background:#fa9d3b;border-radius:2px;font-size:10px;line-height:1;padding:3px 4px}.wx_icon_pay_tag_paid{color:#fa9d3b;background:rgba(250,157,59,0.2)}@media(prefers-color-scheme:dark){.wx_icon_pay_tag{background:#c87d2f}.wx_icon_pay_tag_paid{color:rgba(250,157,59,0.6);background:rgba(250,157,59,0.2)}}.album_read_card{overflow:hidden;margin-top:16px;font-size:14px;color:rgba(0,0,0,0.9);line-height:1.4}.album_read_card .weui-flex__item{min-width:0}.album_read_card .weui-btn__word-wrp{font-size:14px;color:rgba(0,0,0,0.5)}.album_read_card .weui-btn__word-wrp:before{content:\"\\00B7\";margin-left:2px}.album_read_hd{padding:18px 16px;-webkit-box-align:center;-webkit-align-items:center;align-items:center;-webkit-box-pack:center;-webkit-justify-content:center;justify-content:center;position:relative}.album_read_hd:active{opacity:.5}.album_read_source{width:auto;overflow:hidden;text-overflow:ellipsis;white-space:nowrap;word-wrap:normal;color:rgba(0,0,0,0.5)}.album_read_source a:active{opacity:.5}.album_read_directory_access{color:#576b95;margin-left:24px}.album_read_directory_access:active{opacity:.5}.album_read_directory_access:before{content:\"\";display:inline-block;vertical-align:middle;font-size:10px;width:2em;height:2em;margin-top:-0.2em;-webkit-mask:url(\"data:image\/svg+xml;charset=utf8,%3Csvg xmlns='http:\/\/www.w3.org\/2000\/svg' width='20' height='20' viewBox='0 0 20 20'%3E  %3Cg fill='none' fill-rule='evenodd'%3E    %3Cpath fill='%23D8D8D8' d='M0 0h20v20H0z' opacity='0'\/%3E    %3Cpath fill='%23576B95' d='M14.8 13c.11 0 .2.09.2.2v.8a.2.2 0 0 1-.2.2H5.2A.2.2 0 0 1 5 14v-.8c0-.11.09-.2.2-.2h9.6zm0-4c.11 0 .2.09.2.2v.8a.2.2 0 0 1-.2.2H5.2A.2.2 0 0 1 5 10v-.8c0-.11.09-.2.2-.2h9.6zm0-4c.11 0 .2.09.2.2V6a.2.2 0 0 1-.2.2H5.2A.2.2 0 0 1 5 6v-.8c0-.11.09-.2.2-.2h9.6z'\/%3E  %3C\/g%3E%3C\/svg%3E\") no-repeat 50% 50%;mask:url(\"data:image\/svg+xml;charset=utf8,%3Csvg xmlns='http:\/\/www.w3.org\/2000\/svg' width='20' height='20' viewBox='0 0 20 20'%3E  %3Cg fill='none' fill-rule='evenodd'%3E    %3Cpath fill='%23D8D8D8' d='M0 0h20v20H0z' opacity='0'\/%3E    %3Cpath fill='%23576B95' d='M14.8 13c.11 0 .2.09.2.2v.8a.2.2 0 0 1-.2.2H5.2A.2.2 0 0 1 5 14v-.8c0-.11.09-.2.2-.2h9.6zm0-4c.11 0 .2.09.2.2v.8a.2.2 0 0 1-.2.2H5.2A.2.2 0 0 1 5 10v-.8c0-.11.09-.2.2-.2h9.6zm0-4c.11 0 .2.09.2.2V6a.2.2 0 0 1-.2.2H5.2A.2.2 0 0 1 5 6v-.8c0-.11.09-.2.2-.2h9.6z'\/%3E  %3C\/g%3E%3C\/svg%3E\") no-repeat 50% 50%;-webkit-mask-size:cover;mask-size:cover;background-color:currentColor}.album_read_nav_item{position:relative;text-align:center;padding:4px 24px 20px}.album_read_nav_item:before{content:\"\";position:absolute;top:4px;bottom:20px;left:0;width:1px;background:-webkit-linear-gradient(top,rgba(0,0,0,0.03),rgba(0,0,0,0.05) 50%,rgba(0,0,0,0.03) 100%)}.album_read_nav_item:active .album_read_nav_inner{opacity:.5}.album_read_nav_item.album_read_nav_prev{text-align:left}.album_read_nav_item.album_read_nav_next{text-align:right}.album_read_nav_item:first-child:before{display:none}.album_read_nav_item:first-child:last-child{display:-webkit-box;display:-webkit-flex;display:flex;-webkit-box-align:center;-webkit-align-items:center;align-items:center;-webkit-box-pack:center;-webkit-justify-content:center;justify-content:center;padding-top:14px;padding-bottom:32px}.album_read_nav_item:first-child:last-child:before{top:14px;bottom:32px}.album_read_nav_item:first-child:last-child .album_read_nav_btn:before,.album_read_nav_item:first-child:last-child .album_read_nav_btn:after{display:none}.album_read_nav_item:first-child:last-child .album_read_nav_inner{display:-webkit-box;display:-webkit-flex;display:flex;-webkit-box-align:center;-webkit-align-items:center;align-items:center}.album_read_nav_item:first-child:last-child .album_read_nav_inner:before,.album_read_nav_item:first-child:last-child .album_read_nav_inner:after{content:\"\";display:inline-block;vertical-align:middle;font-size:10px;margin-top:-1px;width:1em;height:2em;-webkit-mask-size:cover;mask-size:cover;background-color:currentColor;-webkit-mask-image:url(data:image\/svg+xml,%3Csvg%20width%3D%2212%22%20height%3D%2224%22%20xmlns%3D%22http%3A%2F%2Fwww.w3.org%2F2000%2Fsvg%22%3E%3Cpath%20d%3D%22M2.454%206.58l1.06-1.06%205.78%205.779a.996.996%200%20010%201.413l-5.78%205.779-1.06-1.061%205.425-5.425-5.425-5.424z%22%20fill%3D%22%23B2B2B2%22%20fill-rule%3D%22evenodd%22%2F%3E%3C%2Fsvg%3E);mask-image:url(data:image\/svg+xml,%3Csvg%20width%3D%2212%22%20height%3D%2224%22%20xmlns%3D%22http%3A%2F%2Fwww.w3.org%2F2000%2Fsvg%22%3E%3Cpath%20d%3D%22M2.454%206.58l1.06-1.06%205.78%205.779a.996.996%200%20010%201.413l-5.78%205.779-1.06-1.061%205.425-5.425-5.425-5.424z%22%20fill%3D%22%23B2B2B2%22%20fill-rule%3D%22evenodd%22%2F%3E%3C%2Fsvg%3E)}.album_read_nav_item:first-child:last-child.album_read_nav_prev .album_read_nav_inner:before{transform:matrix(-1,0,0,-1,0,0);-ms-transform:matrix(-1,0,0,-1,0,0);-webkit-transform:matrix(-1,0,0,-1,0,0);margin-right:8px}.album_read_nav_item:first-child:last-child.album_read_nav_prev .album_read_nav_inner:after{display:none}.album_read_nav_item:first-child:last-child.album_read_nav_next .album_read_nav_inner:before{display:none}.album_read_nav_item:first-child:last-child.album_read_nav_next .album_read_nav_inner:after{margin-left:8px}.album_read_nav_item:first-child:last-child .album_read_nav_title{-webkit-line-clamp:1;margin-top:0;-webkit-box-flex:1;-webkit-flex:1;flex:1}.album_read_nav_item:first-child:last-child .album_read_nav_title:before{content:\"\\00B7\";margin-left:4px;margin-right:4px}.album_read_nav_btn{display:block;color:rgba(0,0,0,0.9);font-weight:500}.album_read_nav_btn:before,.album_read_nav_btn:after{content:\"\";display:inline-block;vertical-align:middle;font-size:10px;margin-top:-0.2em;width:1em;height:2em;-webkit-mask-size:cover;mask-size:cover;background-color:currentColor;-webkit-mask-image:url(data:image\/svg+xml,%3Csvg%20width%3D%2212%22%20height%3D%2224%22%20xmlns%3D%22http%3A%2F%2Fwww.w3.org%2F2000%2Fsvg%22%3E%3Cpath%20d%3D%22M2.454%206.58l1.06-1.06%205.78%205.779a.996.996%200%20010%201.413l-5.78%205.779-1.06-1.061%205.425-5.425-5.425-5.424z%22%20fill%3D%22%23B2B2B2%22%20fill-rule%3D%22evenodd%22%2F%3E%3C%2Fsvg%3E);mask-image:url(data:image\/svg+xml,%3Csvg%20width%3D%2212%22%20height%3D%2224%22%20xmlns%3D%22http%3A%2F%2Fwww.w3.org%2F2000%2Fsvg%22%3E%3Cpath%20d%3D%22M2.454%206.58l1.06-1.06%205.78%205.779a.996.996%200%20010%201.413l-5.78%205.779-1.06-1.061%205.425-5.425-5.425-5.424z%22%20fill%3D%22%23B2B2B2%22%20fill-rule%3D%22evenodd%22%2F%3E%3C%2Fsvg%3E)}.album_read_nav_prev .album_read_nav_btn:before{transform:matrix(-1,0,0,-1,0,0);-ms-transform:matrix(-1,0,0,-1,0,0);-webkit-transform:matrix(-1,0,0,-1,0,0);margin-right:8px}.album_read_nav_prev .album_read_nav_btn:after{display:none}.album_read_nav_next .album_read_nav_btn:before{display:none}.album_read_nav_next .album_read_nav_btn:after{margin-left:8px}.album_read_nav_title{overflow:hidden;text-overflow:ellipsis;display:-webkit-box;-webkit-box-orient:vertical;-webkit-line-clamp:2;margin-top:8px;line-height:1.2}.album_read_directory .weui-half-screen-dialog{padding:0;padding:0 constant(safe-area-inset-right) constant(safe-area-inset-bottom) constant(safe-area-inset-left);padding:0 env(safe-area-inset-right) env(safe-area-inset-bottom) env(safe-area-inset-left)}.album_read_directory .weui-half-screen-dialog__hd{padding-left:24px;padding-right:24px}.album_read_directory .weui-icon-close-thin{-webkit-mask-image:url(data:image\/svg+xml,%3Csvg%20width%3D%2212%22%20height%3D%2224%22%20xmlns%3D%22http%3A%2F%2Fwww.w3.org%2F2000%2Fsvg%22%3E%3Cpath%20d%3D%22M2.454%206.58l1.06-1.06%205.78%205.779a.996.996%200%20010%201.413l-5.78%205.779-1.06-1.061%205.425-5.425-5.425-5.424z%22%20fill%3D%22%23B2B2B2%22%20fill-rule%3D%22evenodd%22%2F%3E%3C%2Fsvg%3E);mask-image:url(data:image\/svg+xml,%3Csvg%20width%3D%2212%22%20height%3D%2224%22%20xmlns%3D%22http%3A%2F%2Fwww.w3.org%2F2000%2Fsvg%22%3E%3Cpath%20d%3D%22M2.454%206.58l1.06-1.06%205.78%205.779a.996.996%200%20010%201.413l-5.78%205.779-1.06-1.061%205.425-5.425-5.425-5.424z%22%20fill%3D%22%23B2B2B2%22%20fill-rule%3D%22evenodd%22%2F%3E%3C%2Fsvg%3E);-webkit-transform:rotate(90deg);transform:rotate(90deg);width:14px}.album_read_directory .weui-btn__word-wrp{font-size:14px}.album_read_title{color:#576b95}.album_read_directory_item{color:rgba(0,0,0,0.9);line-height:1.4;padding:24px 16px;position:relative}.album_read_directory_item:before{content:\" \";position:absolute;left:0;top:0;right:0;height:1px;border-top:1px solid rgba(0,0,0,0.1);-webkit-transform-origin:0 0;transform-origin:0 0;-webkit-transform:scaleY(0.5);transform:scaleY(0.5);left:16px;right:16px}.album_read_directory_item:last-child:after{content:\" \";position:absolute;left:0;bottom:0;right:0;height:1px;border-bottom:1px solid rgba(0,0,0,0.1);-webkit-transform-origin:0 100%;transform-origin:0 100%;-webkit-transform:scaleY(0.5);transform:scaleY(0.5);left:16px;right:16px}.album_read_directory_item:active{background-color:rgba(0,0,0,0.05)}.album_read_directory_item .wx_icon_pay_tag{margin-left:8px;margin-top:-2px;display:inline-block;vertical-align:middle}.album_read_directory_current{background-color:rgba(0,0,0,0.05)}.album_read_directory_disabled{color:rgba(0,0,0,0.28)}@media(prefers-color-scheme:dark){.album_read_card{color:rgba(255,255,255,0.8)}.album_read_card .weui-btn__word-wrp{color:rgba(255,255,255,0.5)}.album_read_bd:before{border-top-color:rgba(255,255,255,0.05)}.album_read_directory_access{color:#7d90a9}.album_read_title{color:#7d90a9}.album_read_source{color:rgba(255,255,255,0.5)}.album_read_nav_item:before{background:-webkit-linear-gradient(top,rgba(255,255,255,0.03),rgba(255,255,255,0.05) 50%,rgba(255,255,255,0.03) 100%)}.album_read_nav_btn{color:rgba(255,255,255,0.8)}.album_read_directory_item{color:rgba(255,255,255,0.8)}.album_read_directory_item:before{border-top-color:rgba(255,255,255,0.05)}.album_read_directory_item:active{background-color:rgba(255,255,255,0.1)}.album_read_directory_item:last-child:after{border-bottom-color:rgba(255,255,255,0.05)}.album_read_directory_current{background-color:rgba(255,255,255,0.1)}.album_read_directory_disabled{color:rgba(255,255,255,0.24)}}";
});define("appmsg/more_read_tpl.html.js",[],function(){
return'<p class="read-more__desc">你还可以看</p>\n<div class="read-more__article__area">\n  <# list.forEach(function (item) { #>\n    <div class="read-more__article__item">\n      <a href="javascript:;" class="more_read_link"><#=item.title#></a>\n      <# if (item.fans_read_cnt > 0) { #>\n        <p class="read-more__article__extra"><#=item.fans_read_cnt#>位好友读过</p>\n      <# } #>\n    </div>\n  <# }); #>\n</div>';
});function _defineProperty(e,n,s){
return n in e?Object.defineProperty(e,n,{
value:s,
enumerable:!0,
configurable:!0,
writable:!0
}):e[n]=s,e;
}
var _extends=Object.assign||function(e){
for(var n=1;n<arguments.length;n++){
var s=arguments[n];
for(var i in s)Object.prototype.hasOwnProperty.call(s,i)&&(e[i]=s[i]);
}
return e;
};
define("pages_new/common_share/video/store.js",["pages_new/3rd/vue.js","pages_new/3rd/vuex.js","pages_new/modules/utils/url.js","pages_new/common_share/video/lifecycle_manager.js","pages_new/common_share/video/player/player_store.js","pages_new/common_share/video/related_video_list/related_video_list_store.js","pages_new/common_share/video/like_and_share/like_and_share_store.js","pages_new/common_share/video/topic/topic_store.js","pages_new/modules/comment/comment_store.js","pages_new/modules/reward/reward_store.js","pages_new/common_share/video/player/plugins/tail/tail_store.js","pages_new/common_share/video/player/plugins/danmu/danmu_store.js","pages_new/common_share/video/player/plugins/popup/popup_store.js","pages_new/common_share/video/player/plugins/mid_ad/mid_ad_store.js","pages_new/common_share/video/player/plugins/auto_next/auto_next_store.js"],function(e){
"use strict";
function n(){
return _extends({},window.cgiData,{
uin:window.uin,
biz:window.biz,
appmsgid:window.appmsgid,
idx:window.idx,
scene:window.scene,
subscene:window.subscene,
enterid:window.enterid,
sessionid:window.sessionid,
channel_session_id:window.channel_session_id,
item_show_type:window.item_show_type,
clientversion:window.clientversion,
devicetype:window.devicetype,
continueid:window.continueid,
continueseq:window.continueseq,
reloadid:window.reloadid,
exptype:window.exptype,
expsessionid:window.expsessionid,
source:window.source,
is_temp_url:window.is_temp_url,
appmsg_like_type:window.appmsg_like_type,
pass_ticket:window.pass_ticket,
passparam:window.passparam,
wxtoken:window.wxtoken,
copyright_stat:window.copyright_stat,
need_pay:window.need_pay,
is_pay_subscribe:window.is_pay_subscribe,
msg_title:window.msg_title,
msg_desc:window.msg_desc,
ct:window.ct,
ori_send_time:window.ori_send_time,
msg_link:window.msg_link,
is_login:window.is_login,
user_uin:window.user_uin,
isprofileblock:window.isprofileblock,
round_head_img:window.round_head_img,
kanyikan_video_educate_pic:window.kanyikan_video_educate_pic,
kanyikan_educate_pic:window.kanyikan_educate_pic,
appmsg_type:window.appmsg_type,
send_time:window.send_time,
isPaySubscribe:window.isPaySubscribe,
defaultAvatarUrl:window.defaultAvatarUrl
});
}
function s(){
y.forEach(function(e){
return x.registerModule(e.name,e);
});
}
function i(){
y.forEach(function(e){
return x.unregisterModule(e.name);
});
}
function o(){
j.forEach(function(e){
return x.registerModule([l.name,e.name],e);
});
}
function _(){
j.forEach(function(e){
return x.unregisterModule([l.name,e.name]);
});
}
function t(){
i(),_(),x.commit(u.SET_CGI_DATA,n()),x.commit(u.SET_URL_PARAMS,w.getParams()),s(),
o();
}
function a(e){
x.commit(u.SET_CGI_DATA,n()),x.commit(u.SET_URL_PARAMS,w.getParams()),e&&(s(),o());
}
function r(){
x.commit(u.SET_EXT_RES,{}),x.commit(u.SET_AD_RES,{}),x.commit(u.SET_CGI_DATA,{}),
x.commit(u.SET_URL_PARAMS,{});
}
var d,p=e("pages_new/3rd/vue.js"),m=e("pages_new/3rd/vuex.js"),w=e("pages_new/modules/utils/url.js"),c=e("pages_new/common_share/video/lifecycle_manager.js");
p.use(m);
var u={
SET_EXT_RES:"SET_EXT_RES",
SET_AD_RES:"SET_AD_RES",
SET_CGI_DATA:"SET_CGI_DATA",
SET_URL_PARAMS:"SET_URL_PARAMS",
SET_PRAISE_NUM:"SET_PRAISE_NUM",
SET_RECOMMEND_NUM:"SET_RECOMMEND_NUM",
SET_RECOMMEND_STATUS:"SET_RECOMMEND_STATUS",
SET_PRAISE_STATUS:"SET_PRAISE_STATUS",
SET_SUBSCRIBE_STATUS:"SET_SUBSCRIBE_STATUS",
SET_PUBLIC_RELATED_VIDEO:"SET_PUBLIC_RELATED_VIDEO"
},l=e("pages_new/common_share/video/player/player_store.js"),g=e("pages_new/common_share/video/related_video_list/related_video_list_store.js"),S=e("pages_new/common_share/video/like_and_share/like_and_share_store.js"),E=e("pages_new/common_share/video/topic/topic_store.js"),T=e("pages_new/modules/comment/comment_store.js"),R=e("pages_new/modules/reward/reward_store.js"),y=[g,S,E,T,R],f=e("pages_new/common_share/video/player/plugins/tail/tail_store.js"),A=e("pages_new/common_share/video/player/plugins/danmu/danmu_store.js"),v=e("pages_new/common_share/video/player/plugins/popup/popup_store.js"),h=e("pages_new/common_share/video/player/plugins/mid_ad/mid_ad_store.js"),P=e("pages_new/common_share/video/player/plugins/auto_next/auto_next_store.js"),j=[f,A,v,h,P],x=new m.Store({
modules:_defineProperty({},l.name,l),
state:{
extRes:{},
adRes:{},
cgiData:{},
urlParams:{}
},
mutations:(d={},_defineProperty(d,u.SET_EXT_RES,function(e,n){
e.extRes=n;
}),_defineProperty(d,u.SET_AD_RES,function(e,n){
e.adRes=n;
}),_defineProperty(d,u.SET_CGI_DATA,function(e,n){
e.cgiData=n;
}),_defineProperty(d,u.SET_URL_PARAMS,function(e,n){
e.urlParams=n;
}),_defineProperty(d,u.SET_PRAISE_NUM,function(e,n){
e.extRes.appmsgstat&&e.extRes.appmsgstat.old_like_num&&(e.extRes.appmsgstat.old_like_num=n.praiseNum);
}),_defineProperty(d,u.SET_RECOMMEND_NUM,function(e,n){
e.extRes.appmsgstat&&e.extRes.appmsgstat.like_num&&(e.extRes.appmsgstat.like_num=n.recommendNum);
}),_defineProperty(d,u.SET_RECOMMEND_STATUS,function(e,n){
e.extRes.appmsgstat&&(e.extRes.appmsgstat.liked=n.hasRecommended?1:0);
}),_defineProperty(d,u.SET_PRAISE_STATUS,function(e,n){
e.extRes.appmsgstat&&(e.extRes.appmsgstat.old_liked=n.hasPraised?1:0);
}),_defineProperty(d,u.SET_SUBSCRIBE_STATUS,function(e,n){
e.extRes.is_fans=n.hasSubscribed?1:0;
}),_defineProperty(d,u.SET_PUBLIC_RELATED_VIDEO,function(e,n){
e.cgiData.isPublicRelatedVideo=n.isPublicRelatedVideo;
}),d)
});
return c.register({
getData:t,
init:a,
destroy:r
}),x;
});var _extends=Object.assign||function(n){
for(var e=1;e<arguments.length;e++){
var t=arguments[e];
for(var r in t)Object.prototype.hasOwnProperty.call(t,r)&&(n[r]=t[r]);
}
return n;
};
define("appmsg/comment/comment_report.js",["common/comm_report.js"],function(n){
"use strict";
var e=n("common/comm_report.js"),t=void 0;
switch(1*window.item_show_type){
case 5:
t=1;
break;

case 7:
t=2;
break;

case 8:
t=3;
break;

case 10:
t=4;
break;

case 0:
case 9:
case 11:
default:
t=0;
}
return{
report22214:function(n){
return function(t){
return e.report(22214,_extends({},n,t));
};
}({
BizUin:window.biz||"",
AppMsgId:window.parseInt(window.mid,10)||0,
AppMsgItemIdx:window.parseInt(window.idx,10)||0,
Scene:t,
EnterId:window.parseInt(window.enterid,10)||0,
CommentId64Bit:window.parseInt(window.comment_id,10)||0
}),
report22215:function(n){
return function(t){
return e.report(22215,_extends({},n,t));
};
}({
BizUin:window.biz||"",
AppMsgId:window.parseInt(window.mid,10)||0,
AppMsgItemIdx:window.parseInt(window.idx,10)||0,
Scene:t,
EnterId:window.parseInt(window.enterid,10)||0,
CommentId64Bit:window.parseInt(window.comment_id,10)||0
})
};
});define("appmsg/comment/comment_length.js",["pages/utils.js","biz_wap/utils/mmversion.js","biz_wap/utils/device.js"],function(e){
"use strict";
var t=e("pages/utils.js"),i=e("biz_wap/utils/mmversion.js"),s=e("biz_wap/utils/device.js"),n=i.is_wxwork,r=s.os.pc&&!n;
return{
remindWordCount:10,
getLength:function(e){
return e=t.trim(e),r&&(e=e.replace(/<br\/>/g,"").replace(/\n/g,"")||""),Math.ceil(e.replace(/[^\x00-\xff]/g,"**").length/2);
},
getLimit:function(e){
return"comment"===e?600:140;
}
};
});function _classCallCheck(t,e){
if(!(t instanceof e))throw new TypeError("Cannot call a class as a function");
}
var _createClass=function(){
function t(t,e){
for(var n=0;n<e.length;n++){
var i=e[n];
i.enumerable=i.enumerable||!1,i.configurable=!0,"value"in i&&(i.writable=!0),Object.defineProperty(t,i.key,i);
}
}
return function(e,n,i){
return n&&t(e.prototype,n),i&&t(e,i),e;
};
}();
define("appmsg/comment/comment_input/comment_input.js",["biz_common/dom/event.js","pages/utils.js","appmsg/emotion/selection.js","common/utils.js","appmsg/emotion/dom.js","biz_wap/utils/device.js","biz_wap/utils/mmversion.js","biz_common/tmpl.js","appmsg/comment/comment_input/comment_input.html.js","appmsg/emotion/emotion_pc.js","appmsg/emotion/emotion.js"],function(t){
"use strict";
var e=t("biz_common/dom/event.js"),n=t("pages/utils.js"),i=t("appmsg/emotion/selection.js"),o=t("common/utils.js"),s=t("appmsg/emotion/dom.js"),a=t("biz_wap/utils/device.js"),m=t("biz_wap/utils/mmversion.js"),r=t("biz_common/tmpl.js"),l=t("appmsg/comment/comment_input/comment_input.html.js"),u=a.os.pc&&!m.is_wxwork,c=t(u?"appmsg/emotion/emotion_pc.js":"appmsg/emotion/emotion.js").Emotion,d="comment_primary_counter_warn",p="comment_primary_input_editing",h=o.getInnerHeight(),g=function(t,e){
for(var n=["&#96;","`","&#39;","'","&quot;",'"',"&nbsp;"," ","&gt;",">","&lt;","<","&yen;","¥","&amp;","&"],i=["&","&amp;","¥","&yen;","<","&lt;",">","&gt;"," ","&nbsp;",'"',"&quot;","'","&#39;","`","&#96;"],o=e?i:n,s=0;s<o.length;s+=2)t=t.replace(new RegExp(o[s],"g"),o[s+1]);
return t;
},v=function(t,e){
for(var n=null,i=t.childNodes.length-1;i>=0;i--){
var o=t.childNodes[i];
switch(o.nodeType){
case 1:
var s=o.nodeName.toUpperCase();
if("BR"!==s){
var a=void 0,m=!1;
if("IMG"===s&&o.classList.contains("icon_emotion_single")?a=o:(a=o.textContent||o.innerText||"",
m=!0),a){
var r=m?document.createTextNode(a):a;
e&&!n&&(n=r),t.replaceChild(r,o);
}else t.removeChild(o);
}
break;

case 3:
break;

default:
t.removeChild(o);
}
}
return e?n:void 0;
},f=function(){
function t(e){
var i=this;
_classCallCheck(this,t),this.type=e.type||"comment",this.placeholder=e.placeholder,
this.length=e.length,this.onChange=e.onChange,this.onSubmit=e.onSubmit,this.onShow=e.onShow,
this.onHide=e.onHide,this.onBlur=e.onBlur,this.onClick=e.onClick,this.dom={},this.renderEl=null,
this.target=null,this.value="",this.lastRange=null,this.isShow=!1,this.params=null;
var o=document.createElement("div");
o.innerHTML=r.tmpl(l,{
deviceIsPc:u,
placeholder:this.placeholder,
submitText:e.submitText,
length:this.length,
iconEmotionSwitch:window.icon_emotion_switch,
iconEmotionSwitchActive:window.icon_emotion_switch_active,
iconEmotionSwitchPrimary:window.icon_emotion_switch_primary,
iconEmotionSwitchActivePrimary:window.icon_emotion_switch_active_primary
},!1);
var a=n.qs(".js_wrp",o);
this.dom={
wrp:a,
input:n.qs(".js_input",a),
placeholder:n.qs(".js_placeholder",a),
emotionWrp:n.qs(".js_emotion_wrp",a),
submit:n.qs(".js_submit",a),
counter:n.qs(".js_counter",a),
counterLen:n.qs(".js_counter_len",a)
},document.body.appendChild(a),this.emotion=new c(u?{
emotionSwitch:this.dom.emotionWrp,
input:this.dom.input,
submit:this.dom.submit,
tool:n.qs(".js_tool",a),
onSelect:function(t){
i.insertHTML('<img src="/mpres/zh_CN/htmledition/comm_htmledition/images/pic/common/pic_blank.gif" class="icon_emotion_single '+t.name+'" alt="mo-'+t.title+'">'),
i.emotion.emotionPanelMove();
}
}:{
emotionPanel:s(n.qs(".js_emotion_panel")),
inputArea:s(this.dom.input),
emotionPanelArrowWrp:s(n.qs(".js_emotion_panel_arrow_wrp")),
emotionSwitcher:s(this.dom.emotionWrp),
emotionSlideWrapper:s(n.qs(".js_slide_wrapper")),
emotionNavBar:s(n.qs(".js_navbar")),
submitBtn:s(this.dom.submit),
inputEmotion:function(){
i.dom.submit.disabled=0===n.trim(i.dom.input.value).length;
}
}),this.bindEvent();
}
return _createClass(t,[{
key:"bindEvent",
value:function(){
var t=this;
e.tap(this.dom.submit,function(e){
e.preventDefault(),"function"==typeof t.onSubmit&&t.onSubmit(t.params);
}),u?!function(){
a.os.Mac&&e.on(window,"blur",function(){
t.dom.input&&"none"!==t.dom.input.display&&""!==t.dom.input.innerHTML&&t.blur();
}),e.on(t.dom.input,"focus",function(){
t.dom.wrp.classList.add(p);
}),e.on(t.dom.input,"blur",function(){
t.dom.wrp.classList.remove(p);
}),e.on(t.dom.input,"input",function(){
t.inputHandler();
}),e.tap(t.dom.input,function(){
t.emotion.hide(),"function"==typeof t.onClick&&t.onClick();
}),e.on(t.dom.input,"keyup",function(){
t.saveRange(),t.save();
}),e.on(t.dom.input,"keydown",function(e){
return 13===e.keyCode?(t.saveRange(),t.insertHTML("<br/>"),t.saveRange(),!1):!0;
}),e.on(t.dom.input,"mouseup",function(){
t.saveRange(),t.save();
});
var o=null;
e.on(t.dom.input,"paste",function(){
o&&clearTimeout(o),o=setTimeout(function(){
return i.setCursorToEnd(v(t.dom.input,!0)),t.saveRange(),t.save(),!1;
},10);
}),e.on(document,"click",function(e){
if(t.isShow){
var i=e.target;
n.isParent(i,t.target)||n.isParent(i,t.dom.wrp)||""!==n.trim(t.dom.input.innerHTML)?!t.emotion.isShow||n.isParent(i,t.emotion.dom.emotionPanel)||n.isParent(i,t.dom.emotionWrp)||t.emotion.hide():t.hide();
}
},!1);
}():!function(){
var i=["“”","‘’","（）","《》","〈〉","「」","『』","〔〕","【】","［］","[]","｛｝","{}","()","<>"],o=!1;
e.on(t.dom.input,"input",function(e){
t.dom.submit.disabled=0===n.trim(t.dom.input.value).length,a.os.ios&&e.data&&i.indexOf(e.data)>-1&&(o=!0);
}),a.os.ios&&(e.on(t.dom.input,"click",function(){
o&&(t.blur(),t.focus(),o=!1),"function"==typeof t.onClick&&t.onClick();
}),window.__second_open__&&e.on(t.dom.input,"blur",function(){
"function"==typeof t.onBlur&&t.onBlur();
}));
}();
}
},{
key:"inputHandler",
value:function(){
var t=this.dom.input.innerHTML;
""===t||"<br>"===t?(this.dom.placeholder.style.display="",this.dom.input.innerHTML=""):this.dom.placeholder.style.display="none";
}
},{
key:"show",
value:function(t){
var e=arguments.length<=1||void 0===arguments[1]?{}:arguments[1];
t!==this.renderEl&&("append"===e.renderType?t.appendChild(this.dom.wrp):t.insertAdjacentElement("afterend",this.dom.wrp),
this.renderEl=t),this.target=e.target||t,void 0!==e.placeholder&&e.placeholder!==this.placeholder&&(this.dom.placeholder.innerHTML=e.placeholder,
this.placeholder=e.placeholder),this.params=e.params||null,this.dom.wrp.style.display="";
var n=this.dom.wrp.getBoundingClientRect();
n.top+n.height>=h&&window.scrollTo(0,window.scrollY+n.height),this.dom.input.innerHTML=e.text||"",
this.isShow=!0,u&&(this.inputHandler(),this.lastRange=null,this.save()),this.focus(),
"function"==typeof this.onShow&&this.onShow(t,this.dom.input);
}
},{
key:"hide",
value:function(){
this.isShow=!1,this.dom.wrp.style.display="none",this.emotion.hide(),"function"==typeof this.onHide&&this.onHide(this.target,this.params),
this.params=null;
}
},{
key:"focus",
value:function(){
this.dom.input.focus();
}
},{
key:"blur",
value:function(){
this.dom.input.blur();
}
},{
key:"hideEmotionPannel",
value:function(){
this.emotion.hidePannel();
}
},{
key:"getInput",
value:function(){
return this.dom.input;
}
},{
key:"getSubmit",
value:function(){
return this.dom.submit;
}
},{
key:"saveRange",
value:function(){
this.lastRange=i.getRange();
}
},{
key:"restoreRange",
value:function(){
if(this.lastRange){
var t=i.getSelection();
if(t.addRange)t.removeAllRanges(),t.addRange(this.lastRange);else{
var e=i.getRange();
e.setEndPoint&&(e.setEndPoint("EndToEnd",this.lastRange),e.setEndPoint("StartToStart",this.lastRange)),
e.select();
}
}
}
},{
key:"save",
value:function(){
if(document.execCommand("AutoUrlDetect",!1,!1),this.value=this.emotion.textFilter(g(this.getAfterFilterNodeHtml())),
u){
var t=n.trim(this.value).replace(/(<br\/>)|\n/g,"").length;
this.dom.counterLen.innerText=t,t>this.length?(this.dom.counter.style.display="",
this.dom.counter.classList.add(d),this.dom.submit.disabled=!0):1>t?(this.dom.counter.style.display="none",
this.dom.counter.classList.remove(d),this.dom.submit.disabled=!0):t>=this.length-10?(this.dom.counter.style.display="",
this.dom.counter.classList.remove(d),this.dom.submit.disabled=!1):(this.dom.counter.style.display="none",
this.dom.counter.classList.remove(d),this.dom.submit.disabled=!1);
}
"function"==typeof this.onChange&&this.onChange(this.renderEl,this.dom.input);
}
},{
key:"insertHTML",
value:function(t){
this.focus(),this.dom.input.scrollTop=this.dom.input.scrollHeight,this.restoreRange();
var e=i.getRange();
if(e){
if(e.createContextualFragment){
t+='<img style="width:1px;height:1px;"></img>';
var n=e.createContextualFragment(t),o=n.lastChild,s=i.getSelection();
e.deleteContents(),e.insertNode(n),e.setStartBefore(o),e.setEndAfter(o),s.removeAllRanges(),
s.addRange(e),document.execCommand("Delete",!1,null);
}else e.pasteHTML&&t&&(e.pasteHTML(t),e.select(),e.collapse&&e.collapse(!1));
this.saveRange(),this.save();
}
}
},{
key:"getAfterFilterNodeHtml",
value:function(){
var t=document.createElement("div");
return t.innerHTML=this.dom.input.innerHTML,v(t),t.innerHTML;
}
}]),t;
}();
return f;
});function _classCallCheck(t,e){
if(!(t instanceof e))throw new TypeError("Cannot call a class as a function");
}
var _extends=Object.assign||function(t){
for(var e=1;e<arguments.length;e++){
var o=arguments[e];
for(var i in o)Object.prototype.hasOwnProperty.call(o,i)&&(t[i]=o[i]);
}
return t;
},_createClass=function(){
function t(t,e){
for(var o=0;o<e.length;o++){
var i=e[o];
i.enumerable=i.enumerable||!1,i.configurable=!0,"value"in i&&(i.writable=!0),Object.defineProperty(t,i.key,i);
}
}
return function(e,o,i){
return o&&t(e.prototype,o),i&&t(e,i),e;
};
}();
define("appmsg/comment/comment_dialog/comment_dialog.js",["biz_common/dom/event.js","pages/utils.js","biz_wap/utils/ajax.js","biz_common/utils/url/parse.js","biz_wap/utils/mmversion.js","biz_wap/utils/jsmonitor_report.js","pages/mod/bottom_modal.js","appmsg/comment/comment_list/comment_list.js","biz_common/tmpl.js","appmsg/comment/comment_dialog/c2c_not_support_dialog.html.js","appmsg/comment/comment_dialog/comment_dialog.html.js","biz_wap/utils/device.js","pages/scrollY.js","appmsg/comment/comment_report.js"],function(t){
"use strict";
var e=t("biz_common/dom/event.js"),o=t("pages/utils.js"),i=t("biz_wap/utils/ajax.js"),a=t("biz_common/utils/url/parse.js"),n=t("biz_wap/utils/mmversion.js"),l=t("biz_wap/utils/jsmonitor_report.js"),s=t("pages/mod/bottom_modal.js"),p=t("appmsg/comment/comment_list/comment_list.js"),c=t("biz_common/tmpl.js"),r=t("appmsg/comment/comment_dialog/c2c_not_support_dialog.html.js"),d=t("appmsg/comment/comment_dialog/comment_dialog.html.js"),m=t("biz_wap/utils/device.js"),u=t("pages/scrollY.js"),y=t("appmsg/comment/comment_report.js"),g=y.report22214,_=m.os.pc,h=10,f="https://itunes.apple.com/cn/app/id414478124?mt=8&ls=1",L="https://support.weixin.qq.com/update/",v="page_no_scroll",D="weui-half-screen-dialog_headline",j=function(t){
return window.weui.alert(t,{
className:"weui-pop-zindex-primary"
});
},I=function(){
function t(e){
_classCallCheck(this,t),this.initDialog(e),this.initNotSupportDialog();
}
return _createClass(t,[{
key:"initDialog",
value:function(t){
var i=this;
this.globalData=t.globalData,this.replyData={},this.myId2ContentIdMap={},this.replyListData=null,
this.cmtData=null,this.onGetReplyList=t.onGetReplyList;
var a=document.createElement("div");
a.innerHTML=c.tmpl(d,{
deviceIsPc:_
});
var n=o.qs(".js_bd",a),l=function(){
i.replyListData&&i.replyListData.continue_flag&&i.getReplyList({
success:function(t){
i.replyList.add({
data:t,
type:"reply",
cmtData:i.cmtData
}),i.ending&&(i.ending.style.display=i.replyListData.continue_flag?"none":""),i.dialog.finishPullUpLoad();
},
getNextPage:!0
});
},r=function(){
i.replyListData.scrollTop=i.getScrollTop(),i.replyListData.exposedStatus={
comment:[],
reply:[]
},[i.commentList.getItemList(),i.replyList.getItemList()].forEach(function(t,e){
var o=i.replyListData.exposedStatus[e?"reply":"comment"];
t.forEach(function(t){
t.isExposed&&o.push(t.dataset[e?"replyId":"contentId"]);
});
}),i.replyListData=null,i.cmtData=null,i.dialog.finishPullUpLoad();
};
this.dialogTop=-1,this.dialogBottom=-1,this.canCheckExposedStatus=!1,_?!function(){
a=o.qs(".js_comment_dialog_pc",a),document.body.appendChild(a);
var t=o.qs(".js_bd_main",n),s=!1;
i.dialog={
pullingUpLock:!1,
show:function(){
a.style.display="",document.body.classList.add(v),i.canCheckExposedStatus=!0,i.checkExposedStatus();
},
hide:function(){
r(),a.style.display="none",document.body.classList.remove(v);
},
scrollTo:function(){
n.scrollTo.apply(n,arguments);
},
getScrollEle:function(){
return n;
},
finishPullUpLoad:function(){
this.pullingUpLock=!1;
},
checkReachBoundary:function(){
s&&0!==n.scrollTop||(s=!0,setTimeout(function(){
s=!1;
},50),setTimeout(function(){
!i.dialog.pullingUpLock&&n.scrollTop+n.offsetHeight+100>t.offsetHeight&&(l(),i.dialog.pullingUpLock=!0);
},100));
}
},e.on(o.qs(".js_close",a),"click",function(){
i.dialog.hide();
}),e.on(n,"scroll",function(){
i.dialog.checkReachBoundary(),i.checkExposedStatus();
});
}():this.dialog=new s(n,{
top:"16px",
title:"留言",
extClass:"discuss_more_dialog_wrp weui-half-screen-dialog_wrp",
onPullUpLoad:l,
onHide:r,
onShowAfterAnimation:function(){
i.canCheckExposedStatus=!0,i.checkExposedStatus();
},
onScroll:function(){
i.dialog.contentArea.classList[i.dialog.contentAreaWrp.scrollTop>0?"add":"remove"](D),
i.checkExposedStatus();
}
}),this.bd=n,this.loading=o.qs(".js_loading",n),this.ending=o.qs(".js_end",n),this.empty=o.qs(".js_empty",n),
this.commentList=new p({
globalData:t.globalData,
container:o.qs(".js_comment_list",n),
type:"comment",
canAddComment:t.canAddComment,
onPraise:function(t,e,o,a,n){
i.globalData.cmtList.setLikeInfo({
type:t,
contentId:e,
likeStatus:a,
likeNum:n,
force:!0
});
},
onRender:function(){
i.replyListData&&i.replyListData.exposedStatus&&!function(){
var t=i.replyListData.exposedStatus.comment;
i.commentList.getItemList().forEach(function(e){
t.indexOf(e.dataset.contentId)>-1&&(e.isExposed=!0);
});
}(),i.checkExposedStatus();
},
onRemove:function(t,e){
i.globalData.cmtList.remove({
type:t,
contentId:e
});
},
onEmpty:function(){
i.dialog.hide();
}
}),this.replyList=new p({
globalData:t.globalData,
container:o.qs(".js_reply_list",n),
type:"reply",
canAddComment:t.canAddComment,
onPraise:function(t,e,o,a,n){
i.globalData.cmtList.setLikeInfo({
type:t,
contentId:e,
replyId:o,
likeStatus:a,
likeNum:n
});
},
onRender:function(){
i.replyListData&&i.replyListData.exposedStatus&&!function(){
var t=i.replyListData.exposedStatus.reply;
i.replyList.getItemList().forEach(function(e){
t.indexOf(e.dataset.replyId)>-1&&(e.isExposed=!0);
});
}(),i.checkExposedStatus();
},
onAdd:function(t,e,o,a){
i.globalData.cmtList.updateReplyLen({
newCnt:i.cmtData.reply_new.reply_total_cnt,
contentId:a
}),i.checkExposedStatus();
},
onRemove:function(t,e,o){
var a=i.cmtData.reply_new.reply_total_cnt;
i.globalData.cmtList.remove({
type:t,
contentId:e,
replyId:o.reply_id
}),i.cmtData.reply_new.reply_total_cnt=a,i.globalData.cmtList.updateReplyLen({
newCnt:a,
contentId:e
}),i.checkExposedStatus(),i.dialog.checkReachBoundary(!1,!0);
},
onEmpty:function(t){
"reply"===t&&(i.empty.style.display="");
}
});
}
},{
key:"showDialog",
value:function(t,e){
var o=this;
this.cmtData=t;
var i=t.content_id;
this.replyData[i]&&(this.replyListData=this.replyData[i]),this.getReplyList({
success:function(){
var t=o.replyListData.reply_list;
t.length?(o.empty.style.display="none",o.replyList.render(t,o.cmtData),o.ending&&(o.ending.style.display=o.replyListData.continue_flag?"none":"")):o.empty.style.display="",
o.dialog.scrollTo(0,o.replyListData.scrollTop||0),setTimeout(function(){
o.dialog.finishPullUpLoad();
},300);
},
topReplyId:e
}),this.commentList.render([t]),this.dialog.show();
}
},{
key:"addReply",
value:function(t){
var e=t.data,o=t.mode,i=void 0===o?"push":o,a=t.replyId,n=this.replyListData.reply_list,l=0;
a&&!n.some(function(t){
return l++,t.reply_id===a;
})&&(l=-1),this.replyListData.reply_list="push"===i?l>0&&l<n.length?n.slice(0,l).concat(e,n.slice(l)):n.concat(e):l>0&&l<=n.length?n.slice(0,l-1).concat(e,n.slice(l-1)):e.concat(n);
}
},{
key:"addReplyAndRender",
value:function(t){
this.addReply(t),this.replyList.add({
data:t.data,
mode:t.mode,
type:"reply",
cmtData:this.cmtData,
pos:t.replyId
});
}
},{
key:"removeReply",
value:function(t){
var e=this.replyListData.reply_list,o=-1;
e.some(function(e){
return o++,e.reply_id===t;
})&&e.splice(o,1);
}
},{
key:"getReplyList",
value:function(t){
var e=this,o=t.success,n=t.getNextPage,l=void 0===n?!1:n,s=t.cmtData,p=void 0===s?this.cmtData:s,c=t.topReplyId,r=p.content_id;
new Promise(function(t,o){
var n=!0;
if(l||(null!==e.replyListData?(n=!1,t()):e.replyData[r]&&(e.replyListData=e.replyData[r],
n=!1,t())),n){
e.loading.style.display="",!l&&e.replyList.empty();
var s={
action:"getcommentreply",
appmsgid:window.appmsgid,
idx:window.idx,
comment_id:e.globalData.commentId,
content_id:r,
id:p.id,
limit:h,
max_reply_id:l?e.replyListData.max_reply_id:p.reply_new.max_reply_id
};
void 0!==c&&(s.top_reply_id=c),i({
url:a.join("/mp/appmsg_comment",s,!0),
dataType:"json",
success:function(i){
if(i&&i.base_resp&&0===i.base_resp.ret){
var a=i.reply_list||{
reply_list:[]
};
l&&void 0!==e.replyListData.topReplyId&&(c=e.replyListData.topReplyId),void 0!==c&&(a.reply_list=a.reply_list.filter(function(t,e){
return!l&&0===e||t.reply_id!==c;
})),l?_extends(e.replyListData,{
max_reply_id:a.max_reply_id,
reply_list:e.replyListData.reply_list.concat(a.reply_list),
continue_flag:i.continue_flag
}):(a.continue_flag=i.continue_flag,void 0!==c&&(a.topReplyId=c),e.replyData[r]=a,
e.myId2ContentIdMap[p.my_id]=r,e.replyListData=a),t(a.reply_list),"function"==typeof e.onGetReplyList&&e.onGetReplyList(r,a.reply_list);
}else o();
},
error:function(t){
console.error(t),o();
},
complete:function(){
e.loading.style.display="none";
}
});
}
}).then(o,function(){
j("系统错误，请稍后重试");
});
}
},{
key:"setReplyLikeInfo",
value:function(t){
var e=t.contentId,o=t.replyId,i=t.myId,a=t.likeStatus,n=t.likeNum;
void 0===e&&(e=this.myId2ContentIdMap[i]);
var l=this.replyData[e];
if(l){
var s=p.getDataByKey(l.reply_list,"reply_id",o);
s&&(s.reply_like_status=a,"number"!=typeof n&&(n=s.reply_like_num+(a?1:-1)),s.reply_like_num=n);
}
}
},{
key:"scrollY",
value:function(t,e){
var o={
el:this.dialog.contentAreaWrp,
y:t
};
e?o.speed=300:o.duration=.3,u(o);
}
},{
key:"setMarginBottom",
value:function(t){
this.bd.style.marginBottom=t+"px";
}
},{
key:"checkExposedStatus",
value:function(){
var t=this;
if(this.canCheckExposedStatus){
if(-1===this.dialogTop||-1===this.dialogBottom){
var e=this.dialog.getScrollEle().getBoundingClientRect();
this.dialogTop=e.top,this.dialogBottom=e.bottom;
}
[this.commentList.getItemList(),this.replyList.getItemList()].forEach(function(e,o){
var i=t[o?"replyList":"commentList"];
e.some(function(e){
if(!e.isExposed){
var o=e.getBoundingClientRect(),a=.5*o.height;
if(o.bottom>t.dialogTop+a&&o.top<t.dialogBottom-a){
e.isExposed=!0;
var n=e.dataset,l={
PersonalCommentId:1*n.myId,
ReplyId:0,
IsPopup:1,
IsReplyOther:0,
CommentReplyType:1
};
if(n.replyId){
var s=i.getData({
type:"reply",
contentId:n.contentId,
replyId:1*n.replyId
});
l.ReplyId=s.reply_id,l.IsReplyOther=s.to_nick_name&&s.to_content?1:0;
}
g(l);
}else if(o.top>=t.dialogBottom-a)return!0;
}
return!1;
});
});
}
}
},{
key:"getScrollTop",
value:function(){
return this.dialog.getScrollEle().scrollTop;
}
},{
key:"initNotSupportDialog",
value:function(){
var t=this,i=document.createElement("div");
i.innerHTML=c.tmpl(r,{
comment_c2c_not_support_img:window.comment_c2c_not_support_img
});
var a=o.qs(".js_bd",i),p=o.qs(".js_ft",i);
this.notSupportDialog=new s(a,{
top:"16px",
hasHeader:!1,
footerEl:p,
extClass:"weui-half-screen-dialog_wrp"
}),i=null,e.tap(o.qs(".js_close",p),function(){
t.notSupportDialog.hide();
}),e.tap(o.qs(".js_update",p),function(){
l.setSum(110809,52,1),o.jumpUrl(n.isIOS?f:L,!0),t.notSupportDialog.hide();
});
}
},{
key:"showNotSupportDialog",
value:function(){
this.notSupportDialog.show();
}
}]),t;
}();
return I;
});function _defineProperty(e,t,n){
return t in e?Object.defineProperty(e,t,{
value:n,
enumerable:!0,
configurable:!0,
writable:!0
}):e[t]=n,e;
}
function _classCallCheck(e,t){
if(!(e instanceof t))throw new TypeError("Cannot call a class as a function");
}
var _extends=Object.assign||function(e){
for(var t=1;t<arguments.length;t++){
var n=arguments[t];
for(var i in n)Object.prototype.hasOwnProperty.call(n,i)&&(e[i]=n[i]);
}
return e;
},_createClass=function(){
function e(e,t){
for(var n=0;n<t.length;n++){
var i=t[n];
i.enumerable=i.enumerable||!1,i.configurable=!0,"value"in i&&(i.writable=!0),Object.defineProperty(e,i.key,i);
}
}
return function(t,n,i){
return n&&e(t.prototype,n),i&&e(t,i),t;
};
}();
define("appmsg/comment/comment_list/comment_list.js",["biz_wap/ui/weui.js","biz_common/utils/string/html.js","biz_wap/jsapi/core.js","appmsg/i18n.js","biz_common/utils/url/parse.js","biz_wap/utils/ajax.js","appmsg/retry_ajax.js","biz_common/dom/event.js","pages/utils.js","common/utils.js","biz_wap/utils/openUrl.js","common/keyboard.js","common/actionSheet.js","biz_wap/utils/jsmonitor_report.js","biz_common/tmpl.js","appmsg/comment/comment_list/comment_item.html.js","appmsg/comment/comment_list/item.html.js","biz_wap/utils/mmversion.js","biz_wap/utils/device.js","appmsg/emotion/emotion_pc.js","appmsg/emotion/emotion.js","appmsg/comment/comment_input/comment_input.js","appmsg/comment/comment_write_dialog/comment_write_dialog.js","pages/scrollY.js","appmsg/comment/comment_report.js","appmsg/comment/comment_length.js"],function(e){
"use strict";
e("biz_wap/ui/weui.js"),e("biz_common/utils/string/html.js");
var t=e("biz_wap/jsapi/core.js"),n=e("appmsg/i18n.js"),i=e("biz_common/utils/url/parse.js"),o=e("biz_wap/utils/ajax.js"),a=e("appmsg/retry_ajax.js"),l=e("biz_common/dom/event.js"),r=e("pages/utils.js"),s=e("common/utils.js"),c=e("biz_wap/utils/openUrl.js"),m=e("common/keyboard.js"),p=e("common/actionSheet.js"),d=e("biz_wap/utils/jsmonitor_report.js"),u=e("biz_common/tmpl.js"),y=e("appmsg/comment/comment_list/comment_item.html.js"),_=e("appmsg/comment/comment_list/item.html.js"),f=e("biz_wap/utils/mmversion.js"),g=f.is_wxwork,h=f.isWechat,v=h&&!g,D=e("biz_wap/utils/device.js"),k=D.os.pc&&!g,w=e(k?"appmsg/emotion/emotion_pc.js":"appmsg/emotion/emotion.js"),b=e("appmsg/comment/comment_input/comment_input.js"),L=e("appmsg/comment/comment_write_dialog/comment_write_dialog.js"),C=e("pages/scrollY.js"),I=e("appmsg/comment/comment_report.js"),j=I.report22215,R=e("appmsg/comment/comment_length.js"),T="praised",P="js_item",x="js_comment_item",S="js_reply_item",H="js_comment_praise",M="js_reply_praise",N="praise_num",z="js_comment_del",E="js_reply_del",A="js_comment_main",W="js_extend_comment",B="discuss_media_active",q="js_can_reply",O="js_folder",V="js_comment_reply_pc",F="js_reply_reply_pc",K="js_input_pc",U="js_dropdown",Y="js_comment_complain",Q="js_reply_complain",G="commenting",X="openning",Z="comment_primary_input_multiline",$=2,J=R.getLimit("reply"),et=s.getInnerHeight(),tt=f.isAndroid&&m.canUseCancel,nt=r.getId("activity-name")||"";
nt&&(nt=r.trim(nt.innerText)||"");
var it=function(e){
return window.weui.alert(e,{
className:"weui-pop-zindex-primary"
});
},ot=function(){
var e=document.createElement("input");
e.style.cssText="position: absolute; left: -999999px;",e.readOnly=!0,document.body.appendChild(e);
var t=null;
return{
pageBlur:function(){
e.select();
},
execCommandCopy:function(n){
null===t&&(t=document.createElement("button"),t.style.cssText="position: absolute; left: -999999px;",
document.body.appendChild(t),l.on(t,"click",function(){
document.queryCommandEnabled("copy")?(document.execCommand("copy"),window.weui.toast("复制成功",750)):it("复制失败");
})),e.value=n,e.select(),e.setSelectionRange(0,n.length),t.click();
}
};
}(),at=ot.pageBlur,lt=ot.execCommandCopy,rt=function(){
return f.isWechat?f.isInMiniProgram?0:m.canUseKeyboard?2:f.isIOS&&(f.gtVersion("7.0.12")||s.isNativePage())?2:f.isAndroid&&(f.gtVersion("7.0.13")||s.isNativePage())?2:0:0;
}(),st=function(e){
return e.replace("‮","");
},ct=function(e){
var t=document.createElement("div");
return t.innerHTML=e,Array.prototype.forEach.call(r.qsAll("div.discuss_message_content",t),function(e){
e.innerHTML=w.encode(e.innerHTML);
}),Array.prototype.forEach.call(r.qsAll("p.js_to_content",t),function(e){
e.innerHTML=w.encode(e.innerHTML);
}),t;
},mt=function(){
var e=null,t=null,n=null;
return function(i){
e||(e=r.getId("js_warning_toast"),t=r.qs(".js_content",e)),t.innerHTML=i,n?clearTimeout(n):e.style.display="",
n=setTimeout(function(){
e.style.display="none",n=null;
},750);
};
}(),pt=function(e){
return function(t){
var n=t.logo_url||e;
t.logo_url=n.indexOf("wx.qlogo.cn")>-1?n.replace(/\/132$/,"/96"):n;
};
}("http://mmbiz.qpic.cn/mmbiz/ByCS3p9sHiak6fjSeA7cianwo25C0CIt5ib8nAcZjW7QT1ZEmUo4r5iazzAKhuQibEXOReDGmXzj8rNg/0"),dt=function(){
function e(t){
var n=this;
switch(_classCallCheck(this,e),this.data=[],this.count=0,this.globalData=t.globalData,
this.renderContainer=t.container,this.container=document.createElement("div"),this.renderContainer.appendChild(this.container),
this.type=t.type,this.cmtData=null,this.canAddComment=t.canAddComment,this.onPraise=t.onPraise,
this.onRender=t.onRender,this.onAdd=t.onAdd,this.onRemove=t.onRemove,this.onEmpty=t.onEmpty,
this.beforeShowKeyboard=t.beforeShowKeyboard,this.replyLock=!1,this.isShowAll="mine"!==t.type,
this.openningDropdown=null,this.curReplyEl=null,this.itemList=[],this.type){
case"elected":
this.scene=0;
break;

default:
this.scene="";
}
this.inputInitHeight=0,this.inputInitWidth=0,this.inputValue={},this.input=k?new b({
type:"reply",
placeholder:"留言被公众号精选后，将对所有人可见",
submitText:"回复",
length:J,
onChange:function(e,t){
if(n.inputInitHeight&&t.offsetHeight>n.inputInitHeight)e.classList.add(Z);else if(t.childNodes.length){
var i=document.createRange();
i.selectNodeContents(t.childNodes[0]),i.getBoundingClientRect().width>n.inputInitWidth?e.classList.add(Z):e.classList.remove(Z);
}else e.classList.remove(Z);
},
onSubmit:function(e){
var t=e.type,i=e.cmtData,o=e.replyData,a=e.key;
n.sendReply({
cnt:n.input.value,
type:t,
cmtData:i,
replyData:o,
success:function(){
n.inputValue[a]="";
}
});
},
onShow:function(e,t){
""===n.input.value&&(n.inputInitHeight=t.offsetHeight,n.inputInitWidth=t.offsetWidth-20);
},
onHide:function(e,t){
var i=t.key;
e.parentNode.classList.remove(G),n.inputValue[i]=n.input.value;
}
}):null,this.commentWriteDialog=new L({
type:"elected"===this.type||"mine"===this.type?"reply":"dialog",
canC2CReply:this.globalData.canC2CReply,
onSubmit:function(e,t){
n.commentWriteDialog.disableSubmit(),n.sendReply({
cnt:e,
type:t.type,
cmtData:t.cmtData,
replyData:t.replyData,
success:function(){
n.commentWriteDialog.hide(),n.commentWriteDialog.setInputValue(""),n.inputValue[t.key]="";
},
fail:function(){
n.commentWriteDialog.enableSubmit();
}
});
},
onHide:"comment"!==this.type?function(e,t){
n.inputValue[t.key]=e,n.commentWriteDialog.setInputValue("");
}:null
}),this.bindEvent();
}
return _createClass(e,[{
key:"bindEvent",
value:function(){
var e,t=this,n=(e={},_defineProperty(e,H,function(e){
var n=e.cmtData;
t.praiseComment("comment",n);
}),_defineProperty(e,M,function(e){
var n=e.cmtData,i=e.replyData;
t.praiseComment("reply",n,i);
}),_defineProperty(e,z,function(e){
var n=e.cmtData;
t.delComment("comment",n);
}),_defineProperty(e,E,function(e){
var n=e.cmtData,i=e.replyData;
t.delComment("reply",n,i);
}),_defineProperty(e,W,function(e){
var n=e.cmtData;
t.globalData.cmtDialog.showDialog(n);
}),_defineProperty(e,O,function(e){
var t=e.el;
t.parentNode.classList.add("wx_folder_unfold");
}),e);
k?!function(){
var e,i;
_extends(n,(e={},_defineProperty(e,V,function(e){
var n=e.el,i=e.cmtData,o=e.cmtEl;
t.commentReplyPC("comment",n,o,i);
}),_defineProperty(e,F,function(e){
var n=e.el,i=e.cmtData,o=e.replyData,a=e.replyEl;
t.commentReplyPC("reply",n,a,i,o);
}),_defineProperty(e,U,function(e){
var n=e.el,i=n.parentNode;
t.openningDropdown!==i?(i.classList.add(X),t.openningDropdown=i):(i.classList.remove(X),
t.openningDropdown=null);
}),_defineProperty(e,Y,function(e){
var n=e.cmtData;
t.complain("comment",n);
}),_defineProperty(e,Q,function(e){
var n=e.cmtData,i=e.replyData;
t.complain("reply",n,i);
}),e));
var o=function(){
t.openningDropdown.classList.remove(X),t.openningDropdown=null;
};
l.on(document,"click",function(e){
t.openningDropdown&&!r.isParent(e.target,t.openningDropdown)&&o();
},!1);
var a=function(e){
var n=e.e,i=e.el;
t.openningDropdown&&n.target===i&&o();
};
t.delegatedContainer("mouseout",(i={},_defineProperty(i,A,function(e){
return a(e);
}),_defineProperty(i,S,function(e){
return a(e);
}),i));
}():v&&!function(){
var e,i,o,a,s,c=function(e,n){
var i=n.e,o=n.el,a=n.cmtData,l=n.replyData;
o.classList.contains(q)&&(i.preventDefault(),t.commentReply(e,o,a,l));
};
_extends(n,(e={},_defineProperty(e,A,function(e){
return c("comment",e);
}),_defineProperty(e,S,function(e){
return c("reply",e);
}),e));
var p=!1,d=function(e,n){
var i=n.e,o=n.el,a=n.cmtData,l=n.replyData;
j({
opType:1,
PersonalCommentId:a.my_id,
ReplyId:"reply"===e?l.reply_id:0
}),t.showActionSheet(e,a,l),o.classList.remove(B),i.preventDefault(),p=!0;
};
t.delegatedContainer("longtap",(i={},_defineProperty(i,A,function(e){
return d("comment",e);
}),_defineProperty(i,S,function(e){
return d("reply",e);
}),i));
var u=null,y=null,_=function(e){
var t=e.el;
y=t,u=setTimeout(function(){
t.classList.contains(q)&&t.classList.add(B),u=null;
},100);
};
t.delegatedContainer("touchstart",(o={},_defineProperty(o,A,function(e){
return _(e);
}),_defineProperty(o,S,function(e){
return _(e);
}),o));
var f=function(e){
var t=e.el;
u?(clearTimeout(u),u=null):t.classList.remove(B);
};
t.delegatedContainer("touchmove",(a={},_defineProperty(a,A,function(e){
return f(e);
}),_defineProperty(a,S,function(e){
return f(e);
}),a));
var g=function(e){
var t=e.el;
y=null,setTimeout(function(){
t.classList.remove(B),u&&(clearTimeout(u),u=null),p&&(p=!1,at());
},200);
};
t.delegatedContainer("touchend",(s={},_defineProperty(s,A,function(e){
return g(e);
}),_defineProperty(s,S,function(e){
return g(e);
}),s)),l.on(document,"contextmenu",function(e){
y&&r.isParent(e.target,y)&&(e.preventDefault(),at());
}),2===rt&&m.onGetKeyboardHeight(function(e){
if(t.curReplyEl)if("comment"===t.type||"reply"===t.type){
var n=t.globalData.cmtDialog,i=e+60,o=et-t.curReplyEl.getBoundingClientRect().bottom-i;
n.setMarginBottom(i),n.scrollY(n.getScrollTop()-o,Math.abs(o)<150);
}else if(tt){
var i=e+60,o=et-t.curReplyEl.getBoundingClientRect().bottom-i,a={
y:r.getScrollTop()-o
};
Math.abs(o)<150?a.speed=300:a.duration=.3,document.body.style.marginBottom=i+"px",
C(a);
}
});
}(),this.delegatedContainer("click",n);
}
},{
key:"render",
value:function(e,t){
var n=this;
this.data=e,"reply"!==this.type?this.container.innerHTML=ct(this.getCommentListHTML(e)).innerHTML:(this.cmtData=t,
this.container.innerHTML=ct(this.getReplyListHTML(e,t)).innerHTML),this.itemList=Array.prototype.slice.call(r.qsAll("."+P,this.container)),
"comment"===this.type&&!function(){
var e=r.qs(".js_folder_area",n.container),t=r.qs(".js_content",e);
setTimeout(function(){
t.style.cssText="-webkit-line-clamp: 5;",setTimeout(function(){
t.style.cssText="-webkit-line-clamp: 10;",r.qs(".js_fake_content",e).offsetHeight>t.offsetHeight&&(r.qs("."+O,e).style.display="");
},0);
},0);
}(),"function"==typeof this.onRender&&this.onRender();
}
},{
key:"empty",
value:function(){
this.container.innerHTML="";
}
},{
key:"changeContainer",
value:function(){
var e=arguments.length<=0||void 0===arguments[0]?this.renderContainer:arguments[0];
e&&e!==this.renderContainer&&(this.renderContainer=e,this.renderContainer.appendChild(this.container));
}
},{
key:"add",
value:function(e){
var t=this,n=e.data,i=e.mode,o=void 0===i?"push":i,a=e.type,l=void 0===a?"comment":a,s=e.cmtData,c=e.contentId,m=e.myId,p=e.pos,d=void 0,u=void 0,y=void 0,_=void 0,f=void 0;
"comment"===l?(d="getCommentListHTML",u="content_id",y=this,_="data",f=this.container):(d="getReplyListHTML",
u="reply_id","reply"!==this.type?(s||(s=this.getData(void 0!==c?{
contentId:c
}:{
myId:m
})),s&&(y=s.reply_new,_="reply_list",f=r.qs(".js_reply_list",this.getComment(s.content_id).parentNode))):(s||(s=this.cmtData),
s&&(y=this,_="data",f=this.container))),f&&!function(){
var e=y[_],i=0;
p&&!e.some(function(e){
return i++,e[u]===p;
})&&(i=-1);
var a=!1;
if("push"===o){
if(i>0&&i<e.length){
if(e[i][u]!==n[0][u]){
var r=t.getItemFrag(d,n,s),c=r.frag,m=r.itemList,g="comment"===l?t.getCommentIdx(p):t.getReplyIdx(s.content_id,p);
t.itemList=t.itemList.slice(0,g+1).concat(m,t.itemList.slice(g+1)),f.insertBefore(c,t.itemList[g].nextElementSibling),
y[_]=e.slice(0,i).concat(n,e.slice(i)),a=!0;
}
}else if(!e.length||e[e.length-1][u]!==n[n.length-1][u]){
var h=t.getItemFrag(d,n,s),c=h.frag,m=h.itemList;
if("reply"===l&&"reply"!==t.type){
var g=t.getCommentIdx(s.content_id)+y[_].length;
t.itemList=t.itemList.slice(0,g+1).concat(m,t.itemList.slice(g+1));
}else t.itemList=t.itemList.concat(m);
f.appendChild(c),y[_]=e.concat(n),a=!0;
}
}else if(i>0&&i<=e.length){
if(2>i||e[i-2][u]!==n[n.length-1][u]){
var v=t.getItemFrag(d,n,s),c=v.frag,m=v.itemList,g="comment"===l?t.getCommentIdx(p):t.getReplyIdx(s.content_id,p);
t.itemList=t.itemList.slice(0,g).concat(m,t.itemList.slice(g)),f.insertBefore(c,t.itemList[g]),
y[_]=e.slice(0,i-1).concat(n,e.slice(i-1)),a=!0;
}
}else if(e.length){
if(e[0][u]!==n[0][u]){
var D=t.getItemFrag(d,n,s),c=D.frag,m=D.itemList;
if("reply"===l&&"reply"!==t.type){
var g=t.getCommentIdx(s.content_id);
t.itemList=t.itemList.slice(0,g+1).concat(m,t.itemList.slice(g+1));
}else t.itemList=m.concat(t.itemList);
f.insertBefore(c,f.firstChild),y[_]=n.concat(e),a=!0;
}
}else{
var k=t.getItemFrag(d,n,s),c=k.frag,m=k.itemList;
if("reply"===l&&"reply"!==t.type){
var g=t.getCommentIdx(s.content_id);
t.itemList=t.itemList.slice(0,g+1).concat(m,t.itemList.slice(g+1));
}else t.itemList=m.concat(t.itemList);
f.appendChild(c),y[_]=n.concat(e),a=!0;
}
a&&"function"==typeof t.onAdd&&t.onAdd(n,o,l,s?s.content_id:"",p);
}();
}
},{
key:"remove",
value:function(t){
var n=this,i=t.type,o=void 0===i?"comment":i,a=t.cmtData,l=t.replyData,r=t.contentId,s=t.replyId,c=t.myId;
a||(a=this.getData(void 0!==r?{
contentId:r
}:{
myId:c
})),a&&!function(){
var t=void 0,i=void 0,r=void 0,c=void 0;
if("comment"===o?(t=n.data,i="content_id",r=a.content_id,c=n.getCommentIdx(a.content_id)):("reply"!==n.type?t=a.reply_new.reply_list:(a=n.cmtData,
t=n.data),l||(l=e.getDataByKey(t,"reply_id",s)),l&&(i="reply_id",r=l.reply_id,c=n.getReplyIdx(a.content_id,l.reply_id),
n.globalData.canC2CReply&&"mine"!==n.type&&n.updateReplyLen({
newCnt:--a.reply_new.reply_total_cnt,
cmtData:a
}),n.globalData.canC2CReply&&"elected"===n.type&&n.globalData.cmtDialog.getReplyList({
success:function(){
n.globalData.cmtDialog.removeReply(l.reply_id);
},
cmtData:a
}))),r){
var m=-1;
if(t.some(function(e,t){
return e[i]===r?(m=t,!0):!1;
}),m>-1){
n.count--;
var p=t.splice(m,1)[0],d=void 0;
d="comment"===o?n.itemList.splice(c,p.reply_new.reply_list.length+1)[0].parentNode:n.itemList.splice(c,1)[0],
d.parentNode.removeChild(d),"function"==typeof n.onRemove&&n.onRemove(o,a.content_id,p),
"function"==typeof n.onEmpty&&("comment"===o&&0===n.itemList.length||"reply"===o&&0===a.reply_new.reply_total_cnt)&&n.onEmpty(o);
}
}
}();
}
},{
key:"getData",
value:function(t){
var n=t.type,i=void 0===n?"comment":n,o=t.contentId,a=t.replyId,l=t.myId;
if("reply"===this.type)return"comment"===i?this.cmtData:e.getDataByKey(this.data,"reply_id",a);
var r=void 0;
return r=void 0===o?e.getDataByKey(this.data,"my_id",l):e.getDataByKey(this.data,"content_id",o),
"comment"===i?r:e.getDataByKey(r.reply_new.reply_list,"reply_id",a);
}
},{
key:"getItemList",
value:function(){
return this.itemList;
}
},{
key:"getCommentIdx",
value:function(e){
var t=0;
return this.data.some(function(n){
return n.content_id===e?!0:(t+=n.reply_new.reply_list.length+1,!1);
})?t:-1;
}
},{
key:"getComment",
value:function(e){
if("reply"===this.type)return null;
var t=this.getCommentIdx(e);
return t>-1&&t<this.itemList.length?this.itemList[t]:null;
}
},{
key:"getReplyIdx",
value:function(e,t){
var n=0;
if("reply"===this.type){
if(this.data.some(function(e){
return e.reply_id===t?!0:(n++,!1);
}))return n;
}else if(this.data.some(function(i){
return i.content_id===e?(n++,i.reply_new.reply_list.some(function(e){
return e.reply_id===t?!0:(n++,!1);
}),!0):(n+=i.reply_new.reply_list.length+1,!1);
}))return n;
return-1;
}
},{
key:"getReply",
value:function(e,t){
var n=this.getReplyIdx(e,t);
return n>-1&&n<this.itemList.length?this.itemList[n]:null;
}
},{
key:"setLikeInfo",
value:function(t){
var n=t.type,i=void 0===n?"comment":n,o=t.cmtData,a=t.replyData,l=t.contentId,s=t.replyId,c=t.myId,m=t.likeStatus,p=t.likeNum,d=t.force;
if(o||(o=this.getData(void 0!==l?{
contentId:l
}:{
myId:c
})),o){
var u=void 0,y=void 0,_=void 0;
"comment"===i?(u=o,y="like_status",_="like_num"):(a||(a=e.getDataByKey(o.reply_new.reply_list,"reply_id",s)),
a&&(u=a,y="reply_like_status",_="reply_like_num")),u&&(d||u[y]!==m&&("number"!=typeof p||u[_]!==p))&&(u[y]=m,
"number"!=typeof p&&(p=u[_]+(m?1:-1)),u[_]=p,e.changeLikeStatus("comment"===i?r.qs("."+H,this.getComment(o.content_id)):r.qs("."+M,this.getReply(o.content_id,a.reply_id)),m,p),
"function"==typeof this.onPraise&&this.onPraise(i,o.content_id,"reply"===i?a.reply_id:"",m,p));
}
}
},{
key:"updateReplyLen",
value:function(e){
var t=e.newCnt,n=e.cmtData,i=e.contentId,o=e.myId;
if(n||(n=this.getData(void 0!==i?{
contentId:i
}:{
myId:o
})),n){
var a=this.getComment(n.content_id);
if(a){
var l=r.qs(".js_more_reply",a.parentNode);
l&&(l.style.display=0===t||t===n.reply_new.reply_list.length?"none":"",r.qs(".js_reply_length",l).innerHTML=t);
}
}
}
},{
key:"getCommentListHTML",
value:function(e){
var t=this,n={},i="";
return e.forEach(function(o){
i+=t.getCommentItemHTML(o,t.count++).replace("<mp-reply-list></mp-reply-list>",t.getReplyListHTML(o.reply_new.reply_list,o));
try{
if(t.globalData.reportData&&t.globalData.contentIDs){
var a=o.nick_name+o.content,l=!1,r=t.globalData.reportData.repeatContentID;
n[a]&&(l=!0,r=t.globalData.reportData.repeatContent),t.globalData.contentIDs.indexOf(o.content_id)>-1&&(l=!0,
r=t.globalData.reportData.repeatContentID),t.globalData.contentIDs.push(o.content_id),
n[a]=!0,l&&t.myReport(r,encodeURIComponent(JSON.stringify({
comment_id:t.globalData.commentId,
content_id:o.content_id,
offset:t.globalData.offset,
length:e.length,
url:location.href
})));
}
}catch(s){
console.error(s);
}
}),i;
}
},{
key:"getReplyListHTML",
value:function(e,t){
var n=this;
return e.map(function(e){
return n.getReplyItemHTML(e,t,n.count++);
}).join("");
}
},{
key:"getCommentItemHTML",
value:function(t){
t.time=e.dateToString(t.create_time),t.status="",pt(t),t.content=t.content.htmlDecodeLite().htmlEncodeLite(),
t.nick_name=st(t.nick_name.htmlDecodeLite().htmlEncodeLite()),t.is_from_friend=t.is_from_friend||0,
t.is_from_me="mine"===this.type?1:t.is_from_me||0,t.is_from_author=!1,t.is_from=t.is_from||0,
t.reply_new=t.reply_new||{
reply_list:[]
},t.is_elected="elected"===this.type?1:t.is_elected,t.report_elected=t.is_elected||0,
t.report_friend=t.is_from_friend||0,t.scene=this.scene,t.to_nick_name=t.to_nick_name||"",
t.to_content=(t.to_content||"").htmlDecodeLite().htmlEncodeLite(),t.like_num_format=e.formatLikeNum(t.like_num);
var n={
item:t,
deviceIsPc:k,
isWxWork:g,
type:this.type,
itemType:"comment",
isOversize:!this.isShowAll&&this.getIsOversize(),
supportReply:v,
canC2CReply:this.globalData.canC2CReply
};
return u.tmpl(y,n,!1).replace("<mp-comment-item></mp-comment-item>",u.tmpl(_,n,!1));
}
},{
key:"getReplyItemHTML",
value:function(t,n){
return t.time=e.dateToString(t.create_time),t.content=(t.content||"").htmlDecodeLite().htmlEncodeLite(),
t.is_from_me=1===t.is_from,t.is_from_author=2===t.is_from,t.reply_like_status=t.reply_like_status||0,
t.reply_like_num=t.reply_like_num||0,t.reply_like_num_format=e.formatLikeNum(t.reply_like_num),
t.reply_is_elected="reply"===this.type?1:t.reply_is_elected||0,t.to_reply_del_flag=t.to_reply_del_flag||0,
t.to_content=(t.to_content||"").htmlDecodeLite().htmlEncodeLite(),t.author_like_status=!!t.author_like_status,
"mine"===this.type&&1===t.is_from?(!t.nick_name&&(t.nick_name=this.globalData.nickName),
!t.logo_url&&(t.logo_url=this.globalData.headImg)):t.nick_name=st(t.nick_name.htmlDecodeLite().htmlEncodeLite()),
pt(t),u.tmpl(_,{
item:t,
deviceIsPc:k,
isWxWork:g,
type:this.type,
content_id:n.content_id,
my_id:n.my_id,
itemType:"reply",
isOversize:!this.isShowAll&&this.getIsOversize(),
supportReply:v,
canC2CReply:this.globalData.canC2CReply
},!1);
}
},{
key:"getItemFrag",
value:function(e,t,n){
for(var i=document.createDocumentFragment(),o=[],a=ct(this[e](t,n)).childNodes;a.length;){
var l=a[0];
1===l.nodeType&&o.push(l.classList.contains(P)?l:r.qs("."+P,l)),i.appendChild(l);
}
return{
frag:i,
itemList:o
};
}
},{
key:"getIsOversize",
value:function(){
return this.count>$;
}
},{
key:"delegatedContainer",
value:function(t,n){
var i,o=this;
n=_extends((i={},_defineProperty(i,H,null),_defineProperty(i,M,null),_defineProperty(i,z,null),
_defineProperty(i,E,null),_defineProperty(i,W,null),_defineProperty(i,A,null),_defineProperty(i,S,null),
_defineProperty(i,O,null),i),n);
var a=Object.keys(n);
l.on(this.container,t,function(t){
for(var i=t.target,l="",r=function(e){
return 1===i.nodeType&&i.classList.contains(e)?(l=e,!0):!1;
};i&&i!==t.currentTarget&&!a.some(r);)i=i.parentNode;
if(l&&"function"==typeof n[l]){
for(var s=null,c=null,m=null,p=null,d=i,u=d.classList;d&&!u.contains(x)&&!u.contains(S);)d=d.parentNode,
u=d.classList;
if(u.contains(x))s=o.getData({
contentId:d.dataset.contentId
}),m=d;else if(p=d,"reply"===o.type)s=o.cmtData,c=e.getDataByKey(o.data,"reply_id",1*d.dataset.replyId);else{
for(var y=1*d.dataset.replyId;d&&!d.classList.contains(x);)d=d.parentNode;
s=o.getData({
contentId:d.dataset.contentId
}),m=d,c=e.getDataByKey(s.reply_new.reply_list,"reply_id",y);
}
n[l]({
e:t,
el:i,
cmtData:s,
replyData:c,
cmtEl:m,
replyEl:p
});
}
});
}
},{
key:"praiseComment",
value:function(e,t,n){
var i="/mp/appmsg_comment?action=",o={
comment_id:this.globalData.commentId,
content_id:t.content_id,
item_show_type:window.item_show_type||0,
scene:t.scene
},l=void 0,r=void 0;
"comment"===e?(l=t.like_status?0:1,r=t.like_num+(t.like_status?-1:1),i+="likecomment",
o.appmsgid=window.appmsgid):(l=n.reply_like_status?0:1,r=n.reply_like_num+(n.reply_like_status?-1:1),
i+="like_reply",o.reply_id=n.reply_id),this.setLikeInfo({
type:e,
cmtData:t,
replyData:n,
likeStatus:l,
likeNum:r
}),o.like=l,a({
type:"POST",
url:i,
data:o
});
}
},{
key:"delComment",
value:function(e,t,n){
var a=this;
setTimeout(function(){
window.weui.confirm("comment"===e?"确定删除留言吗？":"确定删除回复吗？",{
className:"weui-pop-zindex-primary",
buttons:[{
label:"取消",
type:"default"
},{
label:"删除",
type:"primary",
onClick:function(){
var l={
scene:a.globalData.reportData.scene,
appmsgid:window.appmsgid,
my_id:t.my_id,
comment_id:a.globalData.commentId,
content_id:t.content_id
};
"comment"===e?l.action="delete":(l.action="deletecommentreply",l.reply_id=n.reply_id),
o({
url:i.join("/mp/appmsg_comment",l,!0),
dataType:"json",
success:function(i){
0===i.ret?a.remove({
type:e,
cmtData:t,
replyData:n
}):it("删除失败，请重试");
},
error:function(){
it("网络错误，请重试");
}
});
}
}]
});
},100);
}
},{
key:"commentReply",
value:function(e,n,i,o){
if(this.checkReplyQualification(i)){
var a="comment"===e&&i.is_from_me||"reply"===e&&i.is_from_me&&(1===o.is_from||2===o.is_from);
if(2===rt){
var l=void 0,s=void 0,c=void 0;
"comment"===e?(l=""+i.content_id,s=i.nick_name,c=i.content):(l=i.content_id+"_"+o.reply_id,
s=o.nick_name,c=o.content),"comment"!==this.type&&(this.inputValue[l]&&r.trim(this.inputValue[l])?(this.commentWriteDialog.setInputValue(this.inputValue[l]),
this.commentWriteDialog.enableSubmit()):(this.commentWriteDialog.setInputValue(""),
this.commentWriteDialog.disableSubmit())),this.commentWriteDialog.show({
nickName:s,
toContent:c,
params:{
type:e,
cmtData:i,
replyData:o,
key:l
}
});
}else if(1===rt&&a){
var m=void 0;
m="comment"===e?i.content:o.content,t.invoke("handleMPPageAction",{
action:"writeCommentReply",
title:nt,
comment_id:this.globalData.commentId,
style:"white",
personal_comment_id:""+i.my_id,
reply_content:m||""
});
}else d.setSum(110809,51,1),this.globalData.cmtDialog.showNotSupportDialog();
}
}
},{
key:"commentReplyPC",
value:function(e,t,n,i,o){
if(this.checkReplyQualification(i)){
if(this.input.isShow&&(this.input.hide(),t===this.input.target))return;
t.parentNode.classList.add(G);
var a=void 0,l=void 0;
"comment"===e?(a=""+i.content_id,l=i.nick_name):(a=i.content_id+"_"+o.reply_id,l=o.nick_name),
this.input.show(r.qs("."+K,n),{
target:t,
renderType:"append",
text:this.inputValue[a],
placeholder:this.globalData.canC2CReply?"回复 "+l+"：":"回复被精选后，对所有人可见",
params:{
type:e,
cmtData:i,
replyData:o,
key:a
}
});
}
}
},{
key:"checkReplyQualification",
value:function(e){
var t=this.globalData.replyFlag;
if(1===t)return mt("回复已被关闭"),!1;
if(e.is_from_me)return!0;
if(0===t)mt("作者已设置其他人不能回复");else if(3!==t||this.globalData.isFans){
if(4!==t||this.globalData.isFansDays)return!0;
mt("作者已设置关注7天后才可回复");
}else mt("作者已设置关注后才可以回复");
return!1;
}
},{
key:"sendReply",
value:function(t){
var n=this,i=t.cnt,a=t.type,l=t.cmtData,r=t.replyData,s=t.success,c=t.fail,m=e.validContent(i,"reply"),p=m.valid,d=m.content;
p&&!this.replyLock&&(this.replyLock=!0,o({
url:"/mp/appmsg_comment?action=addcommentreply",
data:{
appmsgid:window.appmsgid,
idx:window.idx,
comment_id:this.globalData.commentId,
sn:window.sn,
title:nt,
nickname:this.globalData.nickName,
head_img:this.globalData.headImg,
content:d,
enterid:window.enterid,
my_id:l.my_id,
scene:this.globalData.reportData.scene,
to_reply_id:"reply"===a?r.reply_id:"",
content_id:l.content_id
},
type:"POST",
dataType:"json",
success:function(e){
switch(+e.ret){
case 0:
window.weui.toast("已回复",750),k&&n.input.hide(),n.globalData.canC2CReply&&"mine"!==n.type&&n.updateReplyLen({
newCnt:++l.reply_new.reply_total_cnt,
cmtData:l
});
var t={
content:d,
create_time:Math.floor(new Date/1e3),
reply_id:e.reply_id,
reply_like_num:0,
reply_like_status:0,
nick_name:n.globalData.nickName,
logo_url:n.globalData.headImg,
to_content:"reply"===a?r.content:"",
to_nick_name:"reply"===a?r.nick_name:"",
is_from:1,
to_reply_del_flag:0,
reply_is_elected:n.globalData.canC2CReply?1:0
};
switch(n.type){
case"elected":
n.add({
data:[t],
type:"reply",
cmtData:l,
pos:"reply"===a&&r.reply_id
}),n.globalData.canC2CReply&&n.globalData.cmtDialog.getReplyList({
success:function(){
n.globalData.cmtDialog.addReply({
data:[t],
mode:"unshift"
});
},
cmtData:l
});
break;

case"comment":
n.globalData.cmtDialog.addReplyAndRender({
data:[t],
mode:"unshift"
});
break;

case"reply":
n.globalData.cmtDialog.addReplyAndRender({
data:[t],
replyId:r.reply_id
});
break;

case"mine":
n.add({
data:[t],
cmtData:l,
type:"reply"
});
}
return void("function"==typeof s&&s());

case-6:
it("你回复的太频繁了，休息一下吧");
break;

case-7:
it("你还未关注该公众号，不能参与回复");
break;

case-10:
it("字数不能多于"+J+"个");
break;

case-15:
it("回复已关闭");
break;

case-18:
it("你在此留言的回复次数已达上限");
break;

case-20:
it("你还未关注该公众号7天，不能参与回复");
break;

case 167003:
it("你还未付费，不能参与回复");
break;

default:
it("系统错误，请重试");
}
"function"==typeof c&&c();
},
error:function(e){
console.error(e),"function"==typeof c&&c();
},
complete:function(){
n.replyLock=!1;
}
}));
}
},{
key:"showAll",
value:function(){
this.isShowAll||(this.itemList.forEach(function(e){
e.style.display="",e.classList.contains(A)&&(e.parentNode.style.display="");
}),this.isShowAll=!0);
}
},{
key:"showTopItems",
value:function(){
var e=arguments.length<=0||void 0===arguments[0]?2:arguments[0];
return this.itemList.length>e?(this.itemList.some(function(t,n){
return e>n?(t.style.display="",!1):!0;
}),!1):!0;
}
},{
key:"showActionSheet",
value:function(e,n,i){
var o=this;
p.show({
buttons:[{
label:"复制",
onClick:function(){
j({
opType:2,
PersonalCommentId:n.my_id,
ReplyId:"reply"===e?i.reply_id:0
});
var o=("comment"===e?n:i).content;
t.invoke("handleMPPageAction",{
action:"setClipboardData",
text:o
},function(e){
/:ok$/.test(e.err_msg)?window.weui.toast("复制成功",750):window.navigator.clipboard&&window.navigator.clipboard.writeText?window.navigator.clipboard.writeText(o).then(function(){
window.weui.toast("复制成功",750);
},function(){
lt(o);
}):lt(o);
});
}
},{
label:"投诉",
onClick:function(){
j({
opType:3,
PersonalCommentId:n.my_id,
ReplyId:"reply"===e?i.reply_id:0
}),o.complain(e,n,i);
}
}],
noNavShadowWhenUseWeui:"comment"===this.type||"reply"===this.type
});
}
},{
key:"complain",
value:function(e,t,n){
var i={
comment:1,
reply:2
},o="/mp/report?action=getcommentcomplain&comment_id="+this.globalData.commentId+"&content_id="+t.content_id+"&type="+i[e]+"&url="+encodeURIComponent(window.location.href);
"reply"===e&&(o+="&reply_id="+n.reply_id),o+="#wechat_redirect",c.openUrlWithExtraWebview(o);
}
},{
key:"myReport",
value:function(e){
var t=arguments.length<=1||void 0===arguments[1]?"":arguments[1];
"undefined"!=typeof e&&(this.globalData.reportData.idkey?d.setSum(this.globalData.reportData.idkey,e,1):(new Image).src="/mp/jsreport?key="+e+"&content="+t+"&r="+Math.random());
}
}],[{
key:"formatLikeNum",
value:function(e){
return e=parseInt(e,10)>=1e4?(e/1e4).toFixed(1)+"万":e,"en"===window.LANG?n.dealLikeReadShow_en(e):e;
}
},{
key:"dateToString",
value:function(e){
var t=(new Date).getTime(),n=new Date;
n.setDate(n.getDate()+1),n.setHours(0),n.setMinutes(0),n.setSeconds(0),n=n.getTime();
var i=t/1e3-e,o=n/1e3-e,a=new Date(n).getFullYear(),l=new Date(1e3*e);
return 3600>i?Math.ceil(i/60)+"分钟前":86400>o?Math.floor(i/60/60)+"小时前":172800>o?"昨天":604800>o?Math.floor(o/24/60/60)+"天前":l.getFullYear()===a?l.getMonth()+1+"月"+l.getDate()+"日":l.getFullYear()+"年"+(l.getMonth()+1)+"月"+l.getDate()+"日";
}
},{
key:"validContent",
value:function(e){
var t=arguments.length<=1||void 0===arguments[1]?"comment":arguments[1],n=R.getLength(e);
if(0===n)return it("comment"===t?"留言不能为空":"回复不能为空"),{
valid:!1
};
var i=R.getLimit(t);
return n>i?(it("字数不能多于"+i+"个"),{
valid:!1
}):{
valid:!0,
content:e
};
}
},{
key:"getDataByKey",
value:function(e,t,n){
var i=null;
return e.some(function(e){
return e[t]===n?(i=e,!0):!1;
}),i;
}
},{
key:"changeLikeStatus",
value:function(t,n,i){
var o=r.qs("."+N,t);
o.innerHTML=0>=i?"":e.formatLikeNum(i),t.classList[n?"add":"remove"](T);
}
}]),e;
}();
return dt;
});function _classCallCheck(t,e){
if(!(t instanceof e))throw new TypeError("Cannot call a class as a function");
}
var _createClass=function(){
function t(t,e){
for(var n=0;n<e.length;n++){
var i=e[n];
i.enumerable=i.enumerable||!1,i.configurable=!0,"value"in i&&(i.writable=!0),Object.defineProperty(t,i.key,i);
}
}
return function(e,n,i){
return n&&t(e.prototype,n),i&&t(e,i),e;
};
}();
define("appmsg/comment/comment_write_dialog/comment_write_dialog.js",["biz_wap/jsapi/core.js","biz_common/dom/event.js","pages/utils.js","biz_common/tmpl.js","biz_wap/utils/mmversion.js","pages/mod/bottom_modal.js","appmsg/comment/comment_write_dialog/comment_write_dialog.html.js","common/navShadow.js","appmsg/emotion/emotion.js","appmsg/emotion/emotion_panel.js","appmsg/comment/comment_length.js"],function(t){
"use strict";
var e=t("biz_wap/jsapi/core.js"),n=t("biz_common/dom/event.js"),i=t("pages/utils.js"),o=t("biz_common/tmpl.js"),s=t("biz_wap/utils/mmversion.js"),a=t("pages/mod/bottom_modal.js"),l=t("appmsg/comment/comment_write_dialog/comment_write_dialog.html.js"),c=t("common/navShadow.js"),u=t("appmsg/emotion/emotion.js"),r=t("appmsg/emotion/emotion_panel.js"),m=t("appmsg/comment/comment_length.js"),p=function(t){
var e=document.createElement("div");
return e.innerHTML=t,Array.prototype.forEach.call(i.qsAll(".js_to_content",e),function(t){
t.innerHTML=u.encode(t.innerHTML);
}),e;
},h="discuss_write_dialog_android_onfocus",d=[],g=0,b={};
Object.defineProperty(b,"keyboardHeight",{
set:function(t){
d.some(function(e){
return e.dialog.getShowStatus()?(e.bd.setAttribute("style","padding-bottom: "+t+"px; padding-bottom: calc("+t+"px - constant(safe-area-inset-bottom)); padding-bottom: calc("+t+"px - env(safe-area-inset-bottom));"),
!0):!1;
});
}
}),s.isAndroid&&!function(){
var t=document.documentElement.clientHeight||document.body.clientHeight;
n.on(window,"resize",function(){
d.some(function(e){
if(e.dialog.getShowStatus()&&!e.emotionPanel.isShow){
var n=document.documentElement.clientHeight||document.body.clientHeight;
return n===t?e.dialog.getRootEle().classList.remove(h):e.dialog.getRootEle().classList.add(h),
!0;
}
return!1;
});
});
}(),e.on("onGetKeyboardHeight",function(t){
s.isIOS?b.keyboardHeight=t.height:t.height&&(g=t.height,b.keyboardHeight=g),document.body.style.height=window.screen.availHeight-t.height+"px";
});
var f=function(){
function t(e){
var u=this;
_classCallCheck(this,t),d.push(this),this.type=e.type||"comment",this.limit=m.getLimit(this.type),
this.params=null;
var p=document.createElement("div"),h=void 0;
h="comment"===this.type?"留言被公众号精选后，将对所有人可见":e.canC2CReply?"回复将对所有人可见":"回复被公众号精选后，将对所有人可见",
p.innerHTML=o.tmpl(l,{
type:this.type,
placeholder:h
}),this.bd=i.qs(".js_bd",p),this.input=i.qs(".js_input",this.bd);
var f=function(){
u.emotionPanel.hide(),u.input.blur(),"function"==typeof e.onHide&&e.onHide(u.getInputValue(),u.params);
},y={
top:"16px",
extClass:"discuss_write_dialog_wrp",
hasBtn:!0,
innerScrollList:[this.input],
btnClickCb:function(){
u.input.blur(),"function"==typeof e.onSubmit&&e.onSubmit(u.getInputValue(),u.params);
},
onHide:f
};
switch(this.type){
case"comment":
y.title="写留言",y.btnText="提交";
break;

case"dialog":
y.title="写回复",y.btnText="回复",y.transparentMask=!0,y.animationType="right",y.onHide=function(){
c.show(),f();
};
break;

case"reply":
y.title="写回复",y.btnText="回复";
}
this.dialog=new a(this.bd,y),this.dialog.disableBtn(),"dialog"===this.type&&this.dialog.setCloseBtnStyle("back"),
this.replyTo=i.qs(".js_reply_to",this.bd),this.placeholder=i.qs(".js_placeholder",this.bd),
this.toolbar=i.qs(".js_toolbar",this.bd),this.emotion=i.qs(".js_emotion_btn",this.toolbar),
this.inputTips=i.qs(".js_input_tips",this.toolbar),this.toolBar=this.emotion.parentNode,
n.on(this.input,"input",function(){
u.onInputChange();
}),n.on(this.input,"paste",function(t){
var e=t.clipboardData.getData("text"),n=m.getLength(e),i=m.getLength(u.getInputValue());
if(i+n>u.limit){
t.preventDefault();
for(var o=u.limit-i,s="",a=0,l=e.length;l>a&&o>0&&(o-=/[^\x00-\xff]/.test(e[a])?1:.5,
!(0>o));a++)s+=e[a];
u.input.value+=s,u.onInputChange(),u.input.scrollTop=u.input.scrollHeight;
}
}),n.on(this.input,"keydown",function(t){
if(!t.altKey&&!t.ctrlKey)switch(t.keyCode){
case 8:
case 9:
case 12:
case 16:
case 17:
case 18:
case 20:
case 27:
case 33:
case 34:
case 35:
case 36:
case 37:
case 38:
case 39:
case 40:
case 45:
case 46:
case 144:
case 175:
case 174:
case 179:
case 173:
case 172:
case 180:
case 170:
break;

default:
m.getLength(u.getInputValue())>=u.limit&&t.preventDefault();
}
}),n.on(this.input,"touchstart",function(){
u.emotionPanel.hide();
}),n.on(this.input,"focus",function(){
document.body.style.overflow="hidden";
var t=u.input.scrollTop;
u.input.style.height=0,u.input.style.flex="none",u.placeholder.style.display="",
u.placeholder.scrollTop=t;
var e=window.pageYOffset||document.documentElement.scrollTop||document.body.scrollTop||0;
setTimeout(function(){
u.input.style.removeProperty("height"),u.input.style.removeProperty("flex"),u.placeholder.style.display="none",
u.dialog.getBdEle().scrollTop=0,document.documentElement.scrollTop=e,document.body.scrollTop=e;
},300);
}),n.on(this.input,"blur",function(){
document.body.style.removeProperty("overflow"),document.body.style.removeProperty("height");
}),n.on(this.emotion,"click",function(){
u.emotionPanel.isShow?s.isAndroid?setTimeout(function(){
u.input.focus();
}):u.input.focus():u.input.blur(),u.emotionPanel.toggle();
}),this.emotionPanel=new r({
input:this.input,
limit:this.limit,
counter:function(t){
return m.getLength(t);
},
onChange:function(t){
var e=t.type,n=t.value;
("action"!==e||"done"!==n)&&u.onInputChange();
},
onShow:function(t){
b.keyboardHeight=t;
},
onHide:function(){
s.isAndroid&&(b.keyboardHeight=g);
}
});
}
return _createClass(t,[{
key:"show",
value:function(){
var t=arguments.length<=0||void 0===arguments[0]?{}:arguments[0];
this.setReplyTo(t.nickName,t.toContent),this.params=t.params,this.dialog.show(!0,this.input);
}
},{
key:"hide",
value:function(){
this.dialog.hide();
}
},{
key:"onInputChange",
value:function(){
var t=m.getLength(this.getInputValue());
this[t&&t<=this.limit?"enableSubmit":"disableSubmit"](),this.placeholder.value=this.getInputValue(),
this.setInputTips(t);
}
},{
key:"getInputValue",
value:function(){
return this.input.value;
}
},{
key:"setInputValue",
value:function(t){
this.input.value=t,this.onInputChange();
}
},{
key:"enableSubmit",
value:function(){
this.dialog.enableBtn();
}
},{
key:"disableSubmit",
value:function(){
this.dialog.disableBtn();
}
},{
key:"setReplyTo",
value:function(t,e){
t&&e&&(this.replyTo.innerHTML=p("<span>"+t+'</span>:&nbsp;<span class="js_to_content">'+e+"</span>").innerHTML);
}
},{
key:"setInputTips",
value:function(t){
t=t||m.getLength(this.getInputValue()),this.inputTips.innerHTML=t>=this.limit-m.remindWordCount&&t<this.limit?"还可以输入"+(this.limit-t)+"个字":t===this.limit?"达到"+this.limit+"字输入上限":t>this.limit?"已超出"+(t-this.limit)+"字":"";
}
}]),t;
}();
return f;
});function _typeof(e){
return e&&"undefined"!=typeof Symbol&&e.constructor===Symbol?"symbol":typeof e;
}
define("common/keyboard.js",["biz_wap/jsapi/core.js","biz_common/dom/event.js","biz_wap/utils/mmversion.js","pages/bottom_input_bar.js","common/utils.js"],function(e){
"use strict";
var t=e("biz_wap/jsapi/core.js"),n=e("biz_common/dom/event.js"),o=e("biz_wap/utils/mmversion.js"),i=e("pages/bottom_input_bar.js"),s=e("common/utils.js"),c=o.getInner(),l=!1,r=!1,a=!1;
o.isIOS&&o.gtVersion("7.0.16")?(l=!0,r=!0,a=!0):o.isAndroid&&(o.gtVersion("7.0.18")&&"27001634">c||c>="28000038")&&(l=!0,
r=c>="27001700");
var u=[],f=null,d=!1,p=null,y=null,h=null;
l&&(t.on("onGetKeyboardHeight",function(e){
u.length&&u.forEach(function(t){
"function"==typeof t&&t(e.height);
});
}),r&&(f=document.createElement("div"),f.style.cssText="width: 100%; height: 100%; position: fixed; top: 0; background-color: transparent; z-index: 99999999; display: none;",
document.body.appendChild(f),n.on(f,"touchmove",function(e){
d&&e.preventDefault();
})),s.listenStateChange({
cb:function(e){
"onDestroy"===e.state&&(f&&(f.style.display="none"),"function"==typeof y&&y(""),
"function"==typeof h&&h(""));
}
}));
var m=function(){
return l?!0:(console.log("Not support keyboard."),!1);
};
return{
canUseKeyboard:l,
canUseCancel:r,
onGetKeyboardHeight:function(e){
m()&&-1===u.indexOf(e)&&u.push(e);
},
offGetKeyboardHeight:function(e){
if(m()){
var t=u.indexOf(e);
t>-1&&u.splice(t,1);
}
},
show:function(e){
if(m()||e.forceFallback||e.forceFallbackIfUnsupport){
if(y=e.cancel,h=e.hide,a||e.forceFallback){
var n=function(){
p||(p=new i);
var t=!1;
return p.addListener("submit",function(){
t=!0,"function"==typeof e.success&&e.success(p.getContent());
}),p.addListener("hide",function(){
var e=p.getContent();
t||"function"==typeof y&&y(e),"function"==typeof h&&h(e),t=!1;
}),p.addListener("show",function(){
"function"==typeof e.show&&e.show();
}),p.addListener("input",function(){
"function"==typeof e.input&&e.input(p.getContent());
}),p.addListener("fail",function(){
"function"==typeof e.fail&&e.fail();
}),p.setContent(e.text||""),p.setLimit(e.maxLength||0),p.setPlaceholder(e.placeholder||""),
p.show(),{
v:void 0
};
}();
if("object"===("undefined"==typeof n?"undefined":_typeof(n)))return n.v;
}
var o={
text:e.text||"",
placeholder:e.placeholder||"",
maxLength:e.maxLength||0,
showRemindWordCount:e.showRemindWordCount||0,
disableScrollAdjustment:void 0===e.disableScrollAdjustment?!0:e.disableScrollAdjustment
};
e.scrollContentY&&(o.scrollContentY=e.scrollContentY),e.mask&&f&&(f.style.display=""),
d=!!e.disableScroll,t.invoke("showKeyboard",o,function(t){
switch(f&&(f.style.display="none"),t.err_msg){
case"showKeyboard:ok":
"function"==typeof e.success&&e.success(t.text);
break;

case"showKeyboard:cancel":
"function"==typeof y&&y(t.text);
}
"function"==typeof h&&h(t.text);
}),"function"==typeof e.show&&e.show();
}
},
hide:function(){
a&&p&&p.hide();
},
setFullscreenStyle:function(e){
a&&p&&p.setFullscreenStyle(e);
}
};
});