---
title:  web禁止多个客户端同时登录一个账号
date: 2019-12-17
tag:
    - session
    - http
categories: web
---
你一定知道QQ以前不能同时在两个客户端上登录（目前可以手机和电脑同时在线），那么在网站中如何实现这个功能呢。

我这里使用的是session+application实现

1. 当用户首次登录时将session放到application中
2. 下一次登录时从application中找这个session如果存在，且当前的session和上一次不同(不同客户端)则：使前一次的session失效（上一个客户端退出），将新的session更新到application中。
    
```java
protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {

		response.setCharacterEncoding("utf-8");
		response.setContentType("text/plain");
		PrintWriter out = response.getWriter();

		HttpSession session = request.getSession();
		ServletContext application = this.getServletContext();
		String name = "admin";
		String pwd = "123";
		// 从数据库中验证密码是否正确
		if (name == "admin" && pwd == "123") {
			System.out.println("密码验证通过");
			// 获取上一个客户端session
			HttpSession last = (HttpSession) application.getAttribute(name);

			if (last == null) {// 在第一台客户端登录时
				application.setAttribute(name, session);
				System.out.println("第一个客户端登录成功");

			} else if (last != session) {// 不是同一个客户端的的session设置之前的session失效（下线），更新application中的session
				last.invalidate();
				System.out.println("第一个客户端下线");
				application.setAttribute(name, session);
				System.out.println("第二个客户端登陆成功");
			}
			out.write("success");
		} else {
			out.write("failure");
		}

	}
```