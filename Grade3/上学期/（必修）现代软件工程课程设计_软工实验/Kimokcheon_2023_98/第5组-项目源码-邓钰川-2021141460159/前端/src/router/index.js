import { createRouter, createWebHistory } from 'vue-router';
import Login from "../login/Login.vue"
import Register from "../login/Register.vue"

import User from "../user/User.vue"
import AskForLeave from "../student/AskForLeave.vue"
import LeaveSchool from "../student/LeaveSchool.vue"
import Repair from "../student/Repair.vue"
import Update from "../student/Update.vue"
import UpdatePasswd from "../student/UpdatePasswd.vue"

import Admin from "../user/Admin.vue"

import UserMessage from "../admin/UserMessage.vue"
import WorkStation from "../admin/WorkStation.vue"
import AskForLeaveAuditAudit from "../admin/AskForLeaveAudit.vue"
import LeaveSchoolAudit from "../admin/LeaveSchoolAudit.vue"
import RepairAudit from "../admin/RepairAudit.vue"

const routes = [
  { path: '/', component: Login },
  { path: '/register', component: Register },
  { path: '/user', component: User },
  { path: '/student/askForLeave', component: AskForLeave },
  { path: '/student/leaveSchool', component: LeaveSchool },
  { path: '/student/repair', component: Repair },
  { path: '/student/update', component: Update },
  { path: '/student/updatePasswd', component: UpdatePasswd },

  { path: '/admin', component: Admin },
  { path: '/admin/askForLeaveAuditAudit', component: AskForLeaveAuditAudit },
  { path: '/admin/leaveSchoolAudit', component: LeaveSchoolAudit },
  { path: '/admin/repairAudit', component: RepairAudit },
  { path: '/admin/userMessage', component: UserMessage },
  { path: '/admin/workStation', component: WorkStation }
];

const router = createRouter({
  history: createWebHistory(),
  routes
});

export default router;
