file /usr/sbin/hping
set args -zc 10 -S 192.168.0.1 -p 80
layout src
set logging file ./debug.log
set logging on
break antigetopt.c:104
fs cmd
run
# display/s targetname
# p ent->fts_path
# display/s p->p_name
# display/s p->pred_left->p_name
# display/s p->pred_right->p_name
# display/s pred_ptr->p_name
# display/s pred_ptr->pred_left->p_name
# display/s pred_ptr->pred_right->p_name


# 结束并退出
# continue
# set logging off
# quit



