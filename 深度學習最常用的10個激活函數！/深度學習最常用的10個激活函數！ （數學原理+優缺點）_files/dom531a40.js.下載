define("appmsg/my_comment_tpl.html.js",[],function(){
return'<!-- 发表留言 -->\n<#if(window.new_appmsg){#>\n  <div id="js_cmt_mine" class="discuss_container_wrp" style="display:none;">\n    <div class="discuss_container editing access">\n        <div class="discuss_container_inner">\n          <div class="discuss_container_hd">\n            <h2 class="rich_media_title">\n                <#if(window.item_show_type == 10){#>\n                    <#=textPageTitle#>\n                <#}else{#>\n                    <#=window.msg_title.html(1)#>\n                <#}#>\n            </h2><!-- 标题要转义 -->\n            <span id="log"></span>\n            <div class="frm_textarea_box_wrp">\n                <span class="frm_textarea_box">\n                    <#if(window.friend_comment_enabled == 1){#>\n                    <!-- <textarea id="js_cmt_input" class="frm_textarea" placeholder="留言对朋友可见，被公众号筛选后，将对所有人可见。"></textarea> -->\n                    <textarea id="js_cmt_input" class="frm_textarea" placeholder="留言将由公众号筛选后显示，对所有人可见。"></textarea>\n                    <#}else{#>\n                    <textarea id="js_cmt_input" class="frm_textarea" placeholder="留言将由公众号筛选后显示，对所有人可见。"></textarea>\n                    <#}#>\n                    <div class="emotion_tool">\n                        <span class="emotion_switch" style="display:none;"></span>\n                        <span id="js_emotion_switch" class="pic_emotion_switch_wrp">\n                            <img class="pic_default" src="<#=window.icon_emotion_switch#>" alt="">\n                            <img class="pic_active" src="<#=window.icon_emotion_switch_active#>" alt="">\n                            <img class="pic_default_primary" src="<#=window.icon_emotion_switch_primary#>" alt="">\n                            <img class="pic_active_primary" src="<#=window.icon_emotion_switch_active_primary#>" alt="">\n                        </span>\n                    </div>\n                </span>\n            </div>\n            <div class="emotion_panel" id="js_emotion_panel">\n                <span class="emotion_panel_arrow_wrp" id="js_emotion_panel_arrow_wrp">\n                    <i class="emotion_panel_arrow arrow_out"></i>\n                    <i class="emotion_panel_arrow arrow_in"></i>\n                </span>\n                <div class="emotion_list_wrp" id="js_slide_wrapper">\n                    <!--<ul class="emotion_list"></ul>-->\n                    <!--<li class="emotion_item"><i class="icon_emotion"></i></li>-->\n                </div>\n                <ul class="emotion_navs" id="js_navbar">\n                    <!--<li class="emotion_nav"></li>-->\n                </ul>\n            </div>\n            <div class="discuss_btn_wrp"><a id="js_cmt_submit" class="btn btn_primary btn_discuss btn_disabled" href="##">留言</a></div>\n          </div>\n          <div class="discuss_container_bd">\n            <div class="" style="display:none">\n                <div class="mod_title_context">\n                    <strong class="mod_title">我的留言</strong>\n                </div>\n                <ul class="discuss_list" id="js_cmt_mylist"></ul>\n            </div>\n            <div class="weui-loadmore" id="js_mycmt_loading">\n                <i class="weui-loading"></i>\n                <span class="weui-loadmore__tips">正在加载</span>\n            </div>\n            <div id="js_cmt_toast" style="display: none;">\n                <div class="weui-mask_transparent"></div>\n                <div class="weui-toast">\n                    <i class="weui-icon-success-no-circle weui-icon_toast"></i>\n                    <p class="weui-toast__content">已留言</p>\n                </div>\n            </div>\n            <div class="weui-dialog__wrp weui-transition_opacity-hide" id="js_delete_panel_mobile">\n                <div class="weui-mask"></div>\n                <div class="weui-dialog">\n                    <div class="weui-dialog__bd">确定删除留言吗？</div>\n                    <div class="weui-dialog__ft">\n                    <a href="javascript:;" class="weui-dialog__btn weui-dialog__btn_default" id="js_delete_cancel_mobile">取消</a>\n                    <a href="javascript:;" class="weui-dialog__btn weui-dialog__btn_primary" id="js_delete_confirm_mobile">删除</a>\n                    </div>\n                </div>\n            </div>\n          </div>\n        </div>\n    </div>\n  </div>\n<#}else{#>\n    <div id="js_cmt_mine" class="discuss_container editing access" style="display:none;">\n        <div class="discuss_container_inner">\n            <h2 class="rich_media_title"><#=window.msg_title.html(1)#></h2><!-- 标题要转义 -->\n            <span id="log"></span>\n            <div class="frm_textarea_box_wrp">\n                <span class="frm_textarea_box">\n                    <#if(window.friend_comment_enabled == 1){#>\n                    <!-- <textarea id="js_cmt_input" class="frm_textarea" placeholder="留言对朋友可见，被公众号筛选后，将对所有人可见。"></textarea> -->\n                    <textarea id="js_cmt_input" class="frm_textarea" placeholder="留言将由公众号筛选后显示，对所有人可见。"></textarea>\n                    <#}else{#>\n                    <textarea id="js_cmt_input" class="frm_textarea" placeholder="留言将由公众号筛选后显示，对所有人可见。"></textarea>\n                    <#}#>\n                    <div class="emotion_tool">\n                        <span class="emotion_switch" style="display:none;"></span>\n                        <span id="js_emotion_switch" class="pic_emotion_switch_wrp">\n                            <img class="pic_default" src="<#=window.icon_emotion_switch#>" alt="">\n                            <img class="pic_active" src="<#=window.icon_emotion_switch_active#>" alt="">\n                        </span>\n                        <div class="emotion_panel" id="js_emotion_panel">\n                            <span class="emotion_panel_arrow_wrp" id="js_emotion_panel_arrow_wrp">\n                                <i class="emotion_panel_arrow arrow_out"></i>\n                                <i class="emotion_panel_arrow arrow_in"></i>\n                            </span>\n                            <div class="emotion_list_wrp" id="js_slide_wrapper">\n                                <!--<ul class="emotion_list"></ul>-->\n                                <!--<li class="emotion_item"><i class="icon_emotion"></i></li>-->\n                            </div>\n                            <ul class="emotion_navs" id="js_navbar">\n                                <!--<li class="emotion_nav"></li>-->\n                            </ul>\n                        </div>\n                    </div>\n                </span>\n            </div>\n            <div class="discuss_btn_wrp"><a id="js_cmt_submit" class="btn btn_primary btn_discuss btn_disabled" href="##">留言</a></div>\n            <div class="discuss_list_wrp" style="display:none">\n                <div class="rich_tips with_line title_tips discuss_title_line">\n                    <span class="tips">我的留言</span>\n                </div>\n                <ul class="discuss_list" id="js_cmt_mylist"></ul>\n            </div>\n            <div class="rich_tips tips_global loading_tips" id="js_mycmt_loading">\n                <img src="<#=window.icon_loading_white#>" class="rich_icon icon_loading_white" alt="">\n                <span class="tips">加载中</span>\n            </div>\n            <div class="wx_poptips" id="js_cmt_toast" style="display:none;">\n                <img alt="" class="icon_toast" src="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAGoAAABqCAYAAABUIcSXAAAAGXRFWHRTb2Z0d2FyZQBBZG9iZSBJbWFnZVJlYWR5ccllPAAAA3NpVFh0WE1MOmNvbS5hZG9iZS54bXAAAAAAADw/eHBhY2tldCBiZWdpbj0i77u/IiBpZD0iVzVNME1wQ2VoaUh6cmVTek5UY3prYzlkIj8+IDx4OnhtcG1ldGEgeG1sbnM6eD0iYWRvYmU6bnM6bWV0YS8iIHg6eG1wdGs9IkFkb2JlIFhNUCBDb3JlIDUuNS1jMDE0IDc5LjE1MTQ4MSwgMjAxMy8wMy8xMy0xMjowOToxNSAgICAgICAgIj4gPHJkZjpSREYgeG1sbnM6cmRmPSJodHRwOi8vd3d3LnczLm9yZy8xOTk5LzAyLzIyLXJkZi1zeW50YXgtbnMjIj4gPHJkZjpEZXNjcmlwdGlvbiByZGY6YWJvdXQ9IiIgeG1sbnM6eG1wTU09Imh0dHA6Ly9ucy5hZG9iZS5jb20veGFwLzEuMC9tbS8iIHhtbG5zOnN0UmVmPSJodHRwOi8vbnMuYWRvYmUuY29tL3hhcC8xLjAvc1R5cGUvUmVzb3VyY2VSZWYjIiB4bWxuczp4bXA9Imh0dHA6Ly9ucy5hZG9iZS5jb20veGFwLzEuMC8iIHhtcE1NOk9yaWdpbmFsRG9jdW1lbnRJRD0ieG1wLmRpZDoyMTUxMzkxZS1jYWVhLTRmZTMtYTY2NS0xNTRkNDJiOGQyMWIiIHhtcE1NOkRvY3VtZW50SUQ9InhtcC5kaWQ6MTA3QzM2RTg3N0UwMTFFNEIzQURGMTQzNzQzMDAxQTUiIHhtcE1NOkluc3RhbmNlSUQ9InhtcC5paWQ6MTA3QzM2RTc3N0UwMTFFNEIzQURGMTQzNzQzMDAxQTUiIHhtcDpDcmVhdG9yVG9vbD0iQWRvYmUgUGhvdG9zaG9wIENDIChNYWNpbnRvc2gpIj4gPHhtcE1NOkRlcml2ZWRGcm9tIHN0UmVmOmluc3RhbmNlSUQ9InhtcC5paWQ6NWMyOGVjZTMtNzllZS00ODlhLWIxZTYtYzNmM2RjNzg2YjI2IiBzdFJlZjpkb2N1bWVudElEPSJ4bXAuZGlkOjIxNTEzOTFlLWNhZWEtNGZlMy1hNjY1LTE1NGQ0MmI4ZDIxYiIvPiA8L3JkZjpEZXNjcmlwdGlvbj4gPC9yZGY6UkRGPiA8L3g6eG1wbWV0YT4gPD94cGFja2V0IGVuZD0iciI/Pmvxj1gAAAVrSURBVHja7J15rF1TFMbXk74q1ZKHGlMkJVIhIgg1FH+YEpEQJCKmGBpThRoSs5jVVNrSQUvEEENIhGiiNf9BiERICCFIRbUiDa2qvudbOetF3Tzv7XWGffa55/uS7593977n3vO7e5+199p7v56BgQGh0tcmvAUERREUQVEERREUQVEERREUQVEERREUQVEERREUQVEERREUQVEERVAUQVEERVAUQbVYk+HdvZVG8b5F0xj4RvhouB+eCy8KrdzDJc1RtAX8ILxvx98V1GyCSkN98Cx4z/95/Wn4fj6j6tUEeN4wkFSnw1MJqj5NhBfAuwaUHREUg4lqNMmePVsHll/HFhVfe1t3FwpJI8DXCCquDrCWNN4B6Tb4M3Z98aTPmTvh0YHl18PXw29yZiKejoPvcUD6E74yFBJbVDk6Bb7K8aP/Hb4c/tRzEYIqprPhSxzlf4Uvhb/0Xoig8qnHAJ3lqPMzfDH8XZ4LEpRf2sVdA5/sqPO9Qfop70UJyn+/boaPddT5yrq7VUUvTIVJI7q74MMddXR8NB1eXcYvhBpZm0s2w72/o86HFoKvLau/pYaXzjLMdUJ6y0LwtWV9CIIaXtvA8+G9HHV03u5q+K+yH47U0NoRngPv7KjzHDwTLj0bS1BDazfJJlcnOOostC6ysnCT+q80G/sIvFVgeW09D8FPVT0uoP7VfvAD8NjA8pqmuAN+OcYAjso0RbIZ8DGB5TVNcRO8JMaHY9SXSdfa3eeANJimWBLrA7JFiZwIXye+NMUV8CcxP2SRFjXefok7NRjSGZJlWUPvw2/wtNiQirSoXWyMsR28wR7AzzYM0oXw+Y7yK+CLJGeaoqjyrJSdZJD6Ov4+z5y6NJc0Az7NUecHydIUy+v60KNyQHoM3nKI1y7YCFiq0i7uBvgER52vDdKqWn9djhY1Dn4G3n6Ecqm2rF74dvgoR53S0hQxW9RJAZAGW5bSn58QJA27dQ7uIEedjywEX5NKVxCqsY6y+qA+LxFI4+yZ6oH0trWkNan80jygtIUsc5SflgAsDXgehfdx1KkkTRE76tN+Xue2jnTU0Ru1oIbvpt30bBtKhOp5yaaRkts0lic8V1i6dPcIRx2d/l8Y8XtNNEg7OOo8bl1kmmOKnDsO88CaYzejau0hWZqiL7C83oCH4SeTHvwV2BqqsHRVztSEYOmWF80NeXZT6Hd4KflResE9vCnBOlCyGfDNAstHTVPUDWoQ1t3iW+9WNizvlhfd4aerXd+ThqiMfNR6+9LvOOro5OY5JX2H4+F7HZD+kGzlamMgldWiirQsjcwWFbjmqZJteekJLK9pisvgL6RhKvuciZiwzrWWGapfrPy30kBVcSBIrw0aD3PU0XB6cehntq7rTMf7/2iQlktDVdXJLXlg6VjmiYBn6rWSTRCH6hvJ0hQrpcGq8oidsmHpTP8t8DGO9/vcWt9qabiqPgup1yKyQwvC2tSefZ73SSpNkUJ4PlLorlHZ+446nc8f3fIyywlJhwrTuwVSjBa1ccvSxN0hjjoK5xVrYZMd9V6XbFfgBukixTwGLg8sDam3dZR/wZ6L/dJlin1en8LS+bgpFbz3Ygvzu1J1HKxYNqxGpCmaCEo12rrBorD6LRp8UbpcdR5VWhTW35KlKd6QFqjuM2XzwlpnMxTvSkuUwuG/Xlg6NtPjbT6WFimF/VG6LEvXgn8QGDjMbBukVECFwhpoS+CQatfX2Q1q6H7wENHdrfCr0lKleEB9JyxNneus+VJpsVL9TwI6W65LovWIGl3KtVJaLv7LBwYTFEERFEVQFEERFEVQFEERFEVQFEERFEVQFEERFEVQFEERFFWq/hFgADUMN4RzT6/OAAAAAElFTkSuQmCC">\n                <p class="toast_content">已留言</p>\n            </div>\n        </div>\n    </div>\n<#}#>\n<div class="weui-webview-nav" style="display:none;" id="js_fake_bar">\n    <button class="weui-webview-nav__btn_goback" id="js_cmt_goback">goback</button>\n    <button class="weui-webview-nav__btn_forward weui-webview-nav__btn_disabled" disabled="disabled">forward</button>\n</div>\n';
});define("appmsg/cmt_tpl.html.js",[],function(){
return'<#if(window.new_appmsg){#>\n<li class="js_comment_item discuss_item cid<# if (is_from_me == 1) { #><#=my_id#><# } else { #><#=content_id#><# } #>"\n    id="cid<# if (is_from_me == 1) { #><#=my_id#><# } else { #><#=content_id#><# } #>"\n    data-elected="<#=report_elected#>"\n    data-friend="<#=report_friend#>"\n    data-content_id="<#=content_id#>"\n    >\n    <div class="discuss_item_hd">\n      <div class="user_info">\n          <div class="nickname_wrp">\n            <img class="avatar" src="<#=logo_url#>">\n            <strong class="nickname"><#=nick_name#><# if(is_from_friend == 1){ #>(朋友)<# } #></strong>\n            <i class="icon_appmsg_tag theme_tag">作者</i>\n            <# if(typeof is_top === \'number\' && is_top == 1){ #><span class="icon_appmsg_tag">置顶</span><# } #>\n          </div>\n      </div>\n      <# if (!isWxWork) { #>\n      <div class="discuss_opr">\n          <# if (is_from_me == 1) { #>\n            <a class="discuss_opr_meta discuss_del js_del" data-my-id="<#=my_id#>" data-content-id="<#=content_id#>">删除</a>\n          <# } #>\n          <# if(is_elected == 1){ #>\n          <span class="discuss_opr_meta media_tool_meta meta_praise js_comment_praise <# if(like_status == 1){ #>praised<# } #>" data-status="<#=like_status#>" data-content-id=\'<#=content_id#>\' data-scene="<#=scene#>" data-my-id=\'<#=my_id#>\'>\n            <button class="sns_opr_btn sns_praise_btn"><span data-num="<#=like_num#>" data-like="<#=like_status#>" class="sns_opr_num sns_opr_gap praise_num"><# if(like_num_format !== 0){ #><#=like_num_format#> <# } #></span></button>\n          </span>\n          <# } else { #>\n            <span class="discuss_opr_meta">未精选</span>\n          <# } #>\n      </div>\n      <# } #>\n    </div>\n\n    <!-- 预览上次回复内容 -->\n    <!-- <div class="discuss_reply_primary">\n      <strong class="discuss_reply_nickname">昵称：</strong>\n      <p class="discuss_reply_content">Dolor reprehenderit repellendus eos quam.</p>\n    </div> -->\n\n    <div class="discuss_message">\n        <span class="discuss_status"><#=status#></span>\n        <div class="discuss_message_content js_comment_content" data-content="<#=content#>" data-my-id="<#=my_id#>"><#=content#></div>\n    </div>\n    <# if(reply_new && reply_new.reply_list && reply_new.reply_list.length > 0){ #>\n        <# for(var i = 0; i < reply_new.reply_list.length; i++){ #>\n            <div class="reply_result js_reply_item <# if (reply_new.reply_list[i].is_same) {#> reply_result_same <# } #>" <#if (i>=3 && type != \'mine\'){ #> style="display:none" <# } #> data-my-id="<#=my_id#>">\n                <div class="discuss_item_hd">\n                    <# if(reply_new.reply_list[i].is_from_author == 1){ #>\n                        <div class="user_info author_info">\n                        <div class="nickname_wrp">\n                            <img class="avatar" src="<#=logo_url#>">\n                            <div class="nickname">作者昵称作者昵称</div>\n                            <i class="icon_appmsg_tag theme_tag">作者</i>\n                        </div>\n                        </div>\n                    <# } else { #>\n                        <div class="user_info">\n                            <div class="nickname_wrp">\n                            <img class="avatar" src="<#=logo_url#>">\n                            <strong class="nickname"><#=nick_name#></strong>\n                            </div>\n                        </div>\n                    <# } #>\n                    <# if (!isWxWork) { #>\n                    <div class="discuss_opr">\n                        <# if(reply_new.reply_list[i].reply_del_flag == 0){ #>\n                            <# if (reply_new.reply_list[i].is_from_me == 1) { #>\n                                <a class="discuss_opr_meta discuss_del js_reply_del" data-my-id="<#=my_id#>" data-content-id="<#=content_id#>" data-reply-id="<#=reply_new.reply_list[i].reply_id#>">删除</a>\n                            <# } #>\n                            <# if (reply_new.reply_list[i].reply_is_elected == 1){ #>\n                                <span class="discuss_opr_meta media_tool_meta meta_praise js_reply_praise <# if(reply_new.reply_list[i].reply_like_status == 1){ #>praised<# } #>" data-status="<#=reply_new.reply_list[i].reply_like_status#>" data-content-id="<#=content_id#>" data-my-id="<#=my_id#>" data-reply-id=\'<#=reply_new.reply_list[i].reply_id#>\' data-scene="<#=scene#>">\n                                  <button class="sns_opr_btn sns_praise_btn"><span data-num="<#=reply_new.reply_list[i].reply_like_num#>" data-like="<#=reply_new.reply_list[i].reply_like_status#>" class="sns_opr_num sns_opr_gap praise_num"><# if(reply_new.reply_list[i].reply_like_num_format !== 0){ #><#=reply_new.reply_list[i].reply_like_num_format#> <# } #></span></button>\n                                </span>\n                            <# } else { #>\n                                <span class="discuss_opr_meta js_reply_elect_status" data-reply-id=\'<#=reply_new.reply_list[i].reply_id#>\' data-my-id="<#=my_id#>">未精选</span>\n                            <# } #>\n                        <# } #>\n                    </div>\n                    <# } #>\n                </div>\n                <div class="discuss_message">\n                        <# if(reply_new.reply_list[i].reply_del_flag == 1){ #>\n                            <div class="discuss_message_content discuss_message_del">此回复已被删除</div>\n                        <# } else { #>\n                            <div class="discuss_message_content js_reply_content" data-reply-id="<#=reply_new.reply_list[i].reply_id#>" data-my-id="<#=my_id#>" data-content="<#=reply_new.reply_list[i].content#>"><#=reply_new.reply_list[i].content#></div>\n                        <# } #>\n                </div>\n            </div>\n        <# } #>\n    <# } #>\n    <# if(replyListCount > 3 && type != \'mine\'){ #>\n    <div class="discuss_extra_info js_extend_comment discuss_more_access" data-my-id="<#=my_id#>" data-num="<#=replyListCount-3#>">余下<#= replyListCount-3 #>条</div>\n    <# } #>\n    <!-- 上线前暂时隐藏回复入口 -->\n    <# if (supportReply) { #>\n    <p class="discuss_extra_info js_reply_div" data-my-id="<#=my_id#>" <#if (replyListCount > 3 && type != \'mine\'){ #> style="display:none" <# } #>>\n        <a class="js_comment_reply" data-my-id="<#=my_id#>" data-content-id="<#=content_id#>">回复</a>\n    </p>\n    <# } #>\n</li>\n<#}else{#>\n<li class="js_comment_item discuss_item cid<# if (is_from_me == 1) { #><#=my_id#><# } else { #><#=content_id#><# } #>" id="cid<# if (is_from_me == 1) { #><#=my_id#><# } else { #><#=content_id#><# } #>" data-elected="<#=report_elected#>" data-friend="<#=report_friend#>" data-content_id="<#=content_id#>">\n    <# if(is_elected == 1){ #>\n    <div class="discuss_opr">\n        <span class="media_tool_meta tips_global meta_praise js_comment_praise <# if(like_status == 1){ #>praised<# } #>" data-status="<#=like_status#>" data-content-id=\'<#=content_id#>\' data-scene="<#=scene#>">\n            <i class="icon_praise_gray"></i>\n            <span class="praise_num"  data-num="<#=like_num#>"  data-like="<#=like_status#>"><# if(like_num_format !== 0){ #><#=like_num_format#> <# } #></span>\n        </span>\n    </div>\n    <# } #>\n    <div class="user_info">\n        <strong class="nickname"><#=nick_name#><# if(is_from_friend == 1){ #>(朋友)<# } #></strong>\n        <img class="avatar" src="<#=logo_url#>">\n        <# if(typeof is_top === \'number\' && is_top == 1){ #><span class="icon_discuss_top">置顶</span><# } #>\n    </div>\n    <div class="discuss_message">\n        <span class="discuss_status"><#=status#></span>\n        <div class="discuss_message_content"><#=content#></div>\n    </div>\n    <p class="discuss_extra_info">\n        <#=time#>\n        <# if (is_from_me == 1) { #>\n        <a class="discuss_del js_del" data-my-id="<#=my_id#>" data-content-id="<#=content_id#>">删除</a>\n        <# } #>\n    </p>\n    <# if(reply_new && reply_new.reply_list && reply_new.reply_list.length > 0){ #>\n        <div class="reply_result">\n            <div class="discuss_opr">\n                <span class="media_tool_meta tips_global meta_praise js_reply_praise <# if(reply_new.reply_list[0].reply_like_status == 1){ #>praised<# } #>" data-status="<#=reply_new.reply_list[0].reply_like_status#>" data-content-id="<#=content_id#>" data-reply-id=\'<#=reply_new.reply_list[0].reply_id#>\' data-scene="<#=scene#>">\n                    <i class="icon_praise_gray"></i>\n                    <span class="praise_num"  data-num="<#=reply_new.reply_list[0].reply_like_num#>" data-like="<#=reply_new.reply_list[0].reply_like_status#>"><# if(reply_new.reply_list[0].reply_like_num_format !== 0){ #><#=reply_new.reply_list[0].reply_like_num_format#> <# } #></span>\n                </span>\n            </div>\n            <#if(window.new_appmsg){#>\n            <div class="nickname">作者</div>\n            <#}else{#>\n            <div class="nickname">作者回复</div>\n            <# } #>\n            <div class="discuss_message">\n                <div class="discuss_message_content"><#=reply_new.reply_list[0].content#></div>\n            </div>\n            <p class="discuss_extra_info"><#=reply_new.reply_list[0].time#></p>\n        </div>\n    <# } #>\n\n</li>\n<#}#>\n';
});define("sougou/a_tpl.html.js",[],function(){
return'<h3 class="rich_media_area_title">相关文章</h3>\n<ul class="relate_article_list">\n    <# for(var i in list){#>\n    <li class="relate_article_item">\n        <a class="relate_article_link sg_link" href="<#=list[i].url#>" target="_blank"><#=list[i].title#></a>\n    </li>\n    <#}#>\n</ul>\n';
});define("biz_common/utils/report.js",[],function(){
"use strict";
return function(n){
var e=new Image;
e.src=n;
};
});define("appmsg/articleReport.js",["biz_common/utils/string/html.js","biz_common/dom/event.js","biz_wap/utils/mmversion.js"],function(i){
"use strict";
function n(i){
i.dom&&(i.dom.style.display="",t.tap(i.dom,function(){
var n=["https://mp.weixin.qq.com/mp/infringement?url=",encodeURIComponent(i.link.htmlDecode()),"&title=",encodeURIComponent(i.title),"&__biz=",window.biz].join("");
return location.href=n+"#wechat_redirect",!1;
}));
}
i("biz_common/utils/string/html.js");
{
var t=i("biz_common/dom/event.js"),e=i("biz_wap/utils/mmversion.js");
({
not_in_mm:!e.isWp&&-1==navigator.userAgent.indexOf("MicroMessenger")
});
}
return{
init:n
};
});define("appmsg/topic_tpl.html.js",[],function(){
return'<span class="db topic_wrp">\n    <span class="topic_thumb" style="background-image:url({img_url});"></span>\n    <span class="topic_content">\n        <strong class="topic_title">{title}</strong>\n        <span class="topic_desc">{author}</span>\n        <span class="topic_info">\n            <span class="topic_info_extra"><span class="icon_topic"></span>话题</span>\n            <span class="topic_info_primary">相关文章{msg_num}篇</span>\n        </span>\n    </span>\n</span>\n';
});define("appmsg/appmsg_live_tpl.html.js",[],function(){
return'<# if (liveDeleted) { #>\n  <!--直播 已被删除-->\n  <div class="appmsg__live appmsg__live__unusual">直播间已被删除</div>\n<# } else { #>\n  <div class="appmsg__live">\n    <div class="appmsg__live__inner">\n      <div class="appmsg__live__main">\n        <div class="appmsg__live__cover__image" style="background: #FFF url(<#=cover#>) no-repeat center top / cover"></div>\n        <div class="appmsg__live__status__area">\n          <!--未开播-->\n          <div class="appmsg__live__status">\n            <div class="appmsg__live__status__tag"><#=tagStatusWord#></div><span class="appmsg__live__status__info"><#=statusInfoWord#></span>\n          </div>\n        </div>\n        <div class="appmsg__live__like-area js_live_like-area">\n          <# if (isInLive) { #>\n            <div class="appmsg__live__like-animation js_live_like-animation"></div>\n          <# } #>\n          <div class="appmsg__live__like-icon">\n            <div class="person-operation__item__inner mode-filter-black">\n              <div class="appmsg__live__like-icon__image"></div>\n            </div>\n          </div>\n          <div class="appmsg__live__like-info"><#=likeCount#></div>\n        </div>\n      </div>\n      <div class="appmsg__live__extend">\n        <div class="appmsg__live__extend__main">\n          <p class="appmsg__live__title"><#=title#></p>\n          <p class="appmsg__live__desc"><#=desc#></p>\n        </div>\n        <# if (showEntryBtn) { #>\n          <a href="javascript:;" class="appmsg__live__extend__button"><#=btnStatusWord#></a>\n        <# } #>\n      </div>\n    </div>\n  </div>\n<# } #>\n';
});define("appmsg/profile/ban_alert_tpl.html.js",[],function(){
return'<div id="js_profile_ban" style="display: none;">\n    <div class="weui-mask_transparent"></div>\n    <div class="weui-toast">\n        <i class="weui-icon-warn weui-icon_toast"></i>\n        <p class="weui-toast__content">该账号因违规无法跳转</p>\n    </div>\n</div>';
});define("appmsg/profile/mp_profile_tpl.html.js",[],function(){
return' <!-- profile卡片 -->\n<div class="appmsg_card_context wx_profile_card js_wx_profile_card" data-id="<#=id#>" data-isban="<#=isban#>" data-index="<#=index#>">\n  <div class="wx_profile_card_bd">\n    <div class="wx_profile weui-flex">\n      <div class="wx_profile_hd">\n        <# if(round_head_img) { #>\n        <img class="wx_profile_avatar" src="<#=round_head_img#>" alt="<#=nickname#>">\n        <# } else {#>>\n        <img class="wx_profile_avatar" src="http://mmbiz.qpic.cn/mmbiz/a5icZrUmbV8p5jb6RZ8aYfjfS2AVle8URwBt8QIu6XbGewB9wiaWYWkPwq4R7pfdsFibuLkic16UcxDSNYtB8HnC1Q/0" alt="<#=nickname#>">\n        <# } #>\n      </div>\n      <div class="wx_profile_bd weui-flex weui-flex__item">\n        <div class="weui-flex__item">\n          <strong class="wx_profile_nickname">\n              <#  if(nickname) { #>\n                <#=nickname#>\n\n              <# } else { #>\n                <#=alias#>\n              <#}#>\n          </strong>\n          <div class="wx_profile_desc"><#=signature#></div>\n          <div class="wx_profile_tips" id="js_profile_desc">\n            <span class="wx_profile_tips_meta" id="js_profile_article" <#if (original_num === 0){ #> style="display:none" <# } #>><#=original_num#>篇原创内容</span>\n            <!-- <span class="wx_profile_tips_meta" id="js_profile_friends"></span> -->\n          </div>\n        </div>\n        <i class="weui-icon-arrow"></i>\n      </div>\n    </div>\n  </div>\n  <div class="wx_profile_card_ft">公众号</div>\n</div>\n';
});define("appmsg/channel/report_live.js",["common/comm_report.js"],function(n){
"use strict";
var e=n("common/comm_report.js"),o=function(n,o,i,t){
var r=0;
try{
r=1*window.atob(window.biz);
}catch(w){}
e.report(22035,{
BizUin:r,
AppMsgID:window.parseInt(window.mid,10)||0,
ItemIndex:window.parseInt(window.idx,10)||0,
Scene:window.parseInt(window.scene,10)||0,
Enterid:window.parseInt(window.enterid,10)||0,
Action:n,
Status:t||"",
ActionTS:Math.ceil(Date.now()/1e3),
Noticeid:o||"",
Username:i||""
});
};
return{
report:o
};
});define("appmsg/channel/time_format.js",[],function(){
"use strict";
var e=function(e){
var t=e+"";
return t.length>=2?t:"0"+t;
},t=function(t){
var a=new Date(1e3*t);
return a.getFullYear()<=(new Date).getFullYear()?e(a.getMonth()+1)+"月"+e(a.getDate())+"日 "+e(a.getHours())+":"+e(a.getMinutes()):a.getFullYear()+"年"+e(a.getMonth()+1)+"月"+e(a.getDate())+"日 "+e(a.getHours())+":"+e(a.getMinutes());
},a=function(e,t){
var a=void 0;
switch(e=parseInt(e,10),t=parseInt(t,10),e){
case 0:
a=0===t?"预约":"已预约";
break;

case 1:
a="已失效";
break;

case 2:
a="观看";
break;

case 3:
a="已结束";
break;

default:
a="预约";
}
return a;
},r=function(e,a){
var r=void 0;
switch(a=parseInt(a,10)){
case 0:
r="将在"+t(e)+" 直播";
break;

case 1:
case 3:
r=t(e)+" 直播";
break;

case 2:
r="正在直播";
break;

default:
r="正在直播";
}
return r;
};
return{
getFullTime:t,
getStatusWording:a,
getStatusDesc:r
};
});define("appmsg/channel/video_snap_tpl.html.js",[],function(){
return'<# if(snapType === \'video\'){ #>\n<div class="wxw_wechannel_card appmsg_card_context js_wechannel_video_card js_wechannel_video_context">\n  <div class="wxw_wechannel_card_bd">\n    <div class="wxw_wechannel_video_context" style="background-image:url(<#=url#>)">\n      <i class="weui-play-btn_primary"></i>\n    </div>\n    <div class="wxw_wechannel_profile weui-flex">\n      <# if(headImgUrl){ #>\n      <img class="wxw_wechannel_avatar" src="<#=headImgUrl#>" data-disable-preview="1">\n      <# }else{ #>\n      <img class="wxw_wechannel_avatar" src="http://mmbiz.qpic.cn/mmbiz/a5icZrUmbV8p5jb6RZ8aYfjfS2AVle8URwBt8QIu6XbGewB9wiaWYWkPwq4R7pfdsFibuLkic16UcxDSNYtB8HnC1Q/0" data-disable-preview="1">\n      <# } #>\n      <strong class="wxw_wechannel_nickname"><#=nickname#></strong>\n    </div>\n    <# if(desc){ #>\n    <div class="wxw_wechannel_desc">\n      <#=desc#>\n    </div>\n    <# } #>\n    <!-- 不可引用时show出来即可 -->\n    <# if(flag === 1){ #>\n    <div class="wxw_wechannel_msg">\n      该视频号动态已删除    </div>\n    <# } else if (flag === 2) { #>\n      <div class="wxw_wechannel_msg">\n        无法浏览该视频号动态      </div>\n    <# } #>\n  </div>\n  <div class="wxw_wechannel_card_ft weui-flex">\n    <i class="wxw_wechannel_logo"></i>视频号  </div>\n</div>\n<# } else if (snapType === \'image\'){  #>\n<div class="wxw_wechannel_card appmsg_card_context js_wechannel_img_card js_wechannel_img_context">\n  <div class="wxw_wechannel_card_bd">\n    <div class="wxw_wechannel_img_context">\n        <ul class="wxw_wechannel_img_list js_wechannel_img_list" id="js_wechannel_img_list" data-poster-src="<#=url#>" data-disable-preview="1">\n            <li class="wxw_wechannel_img js_wechannel_img" data-w="1000" data-ratio="1" style="background-image:url(<#=url#>)" data-disable-preview="1"></li>\n        </ul>\n        <ul class="wxw_wechannel_img_navs js_wechannel_img_navs">\n          <# for(var i = 0; i < imgCount; i++){ #>\n            <li class="wxw_wechannel_img_nav <# if(i === 0){ #>  wxw_wechannel_img_nav_current <# } #> "></li>\n          <# } #>\n        </ul>\n    </div>\n    <div class="wxw_wechannel_profile weui-flex">\n      <# if(headImgUrl){ #>\n        <img class="wxw_wechannel_avatar" src="<#=headImgUrl#>" data-disable-preview="1">\n        <# }else{ #>\n        <img class="wxw_wechannel_avatar" src="http://mmbiz.qpic.cn/mmbiz/a5icZrUmbV8p5jb6RZ8aYfjfS2AVle8URwBt8QIu6XbGewB9wiaWYWkPwq4R7pfdsFibuLkic16UcxDSNYtB8HnC1Q/0" data-disable-preview="1">\n        <# } #>\n      <strong class="wxw_wechannel_nickname"><#=nickname#></strong>\n    </div>\n    <# if(desc){ #>\n    <div class="wxw_wechannel_desc">\n      <#=desc#>\n    </div>\n    <# } #>\n    <# if(flag === 1){ #>\n      <div class="wxw_wechannel_msg">\n        该视频号动态已删除      </div>\n    <# } else if (flag === 2) { #>\n      <div class="wxw_wechannel_msg">\n        无法浏览该视频号动态      </div>\n    <# } #>\n  </div>\n  <div class="wxw_wechannel_card_ft weui-flex">\n    <i class="wxw_wechannel_logo"></i>视频号  </div>\n</div>\n<# } else if (snapType === \'live\') { #>\n<div class="wxw_wechannel_card appmsg_card_context wxw_wechannel_card_live js_wechannel_live_card" data-noticeid="<#=noticeid#>" data-username="<#=username#>">\n  <div class="wxw_wechannel_card_bd">\n    <div class="wxw_wechannel_live_context weui-flex">\n      <div class="wxw_wechannel_live_hd">\n        <img class="wxw_wechannel_live_avatar" src="<#=headImgUrl#>" alt="">\n      </div>\n      <div class="wxw_wechannel_live_bd weui-flex__item">\n        <strong class="wxw_wechannel_live_nickname"><#=nickname#></strong>\n        <div class="wxw_wechannel_live_desc js_wechannel_live_desc"><#=desc#></div>\n      </div>\n      <div class="wxw_wechannel_live_ft js_wechannel_operation_area">\n        <button class="weui-btn weui-btn_mini wxw_wechannel_live_btn js_channel_btn_operation <# if((status !== 0 && status !== 2)|| reservation === 1){ #>weui-btn_disabled<# } #>" data-reservation="<#=reservation#>" data-noticeid="<#=noticeid#>" data-username="<#=username#>" data-status="<#=status#>" type="button">\n          <i class="icon_wxw_wechannel_live js_wechannnel_live" <#if (status !== 2){ #> style="display:none" <# } #>></i>\n          <span class="js_channel_btn_operation_wording"><#=liveWording#></span>\n        </button>\n      </div>\n    </div>\n    <# if (flag === 1) { #>\n      <div class="wxw_wechannel_msg">\n        无法浏览该视频号动态      </div>\n    <# } #>\n  </div>\n  <div class="wxw_wechannel_card_ft weui-flex">\n    <i class="wxw_wechannel_logo"></i>视频号  </div>\n</div>\n<# } #>\n';
});define("appmsg/appmsg_card.js",["biz_common/dom/event.js"],function(t){
"use strict";
function a(t,a){
var n=a?t.querySelector(a):t;
c.on(t,"touchstart",function(c){
var o=c.target;
a&&n.contains(o)||t.classList.add("appmsg_card_custom_active");
}),c.on(t,"touchend",function(c){
var o=c.target;
a&&n.contains(o)||t.classList.remove("appmsg_card_custom_active");
});
}
var c=t("biz_common/dom/event.js");
return{
addAppmsgCardTouchEvent:a
};
});define("biz_common/dom/offset.js",[],function(){
"use strict";
function f(f){
if(!f)return{};
for(var t=0,e=0,o=parseInt(document.body.style.marginTop,10)||0;f.offsetParent;)t+=f.offsetTop,
e+=f.offsetLeft,f=f.offsetParent;
return{
offsetTop:t>o?t-o:t,
offsetLeft:e
};
}
return{
getOffset:f
};
});define("appmsg/emotion/dom.js",["biz_common/dom/event.js"],function(t){
"use strict";
function e(t){
if("string"==typeof t){
document.querySelectorAll||!function(){
var t=document.createStyleSheet(),e=function(e,n){
var i,o=document.all,r=o.length,u=[];
for(t.addRule(e,"foo:bar"),i=0;r>i&&!("bar"===o[i].currentStyle.foo&&(u.push(o[i]),
u.length>n));i+=1);
return t.removeRule(0),u;
};
document.querySelectorAll=function(t){
return e(t,1/0);
};
}();
var e=document.querySelectorAll(t);
}else e=[t];
return{
el:e,
on:function(t,e){
return this.each(function(n){
i.on(n,t,e);
}),this;
},
hide:function(){
return this.each(function(t){
t.style.display="none";
}),this;
},
show:function(){
return this.each(function(t){
t.style.display="block";
}),this;
},
each:function(t){
return n(this.el,t),this;
},
width:function(){
return this.el[0].clientWidth;
},
css:function(t){
return this.each(function(e){
for(var n in t)e.style[n]=t[n];
}),this;
},
attr:function(t,e){
var n=this.el[0];
return e?(n.setAttribute(t,e),this):n.getAttribute(t);
},
append:function(t){
return t.el&&(t=t.el[0]),this.el[0].appendChild(t),this;
},
html:function(t){
this.each(function(e){
e.innerHTML=t;
});
}
};
}
function n(t,e){
for(var n=0,i=t.length;i>n;n++)e(t[n],n);
}
var i=t("biz_common/dom/event.js");
return e.el=function(t){
return document.createElement(t);
},e.later=function(t){
setTimeout(t,3);
},e.log=function(){},e.each=n,e;
});