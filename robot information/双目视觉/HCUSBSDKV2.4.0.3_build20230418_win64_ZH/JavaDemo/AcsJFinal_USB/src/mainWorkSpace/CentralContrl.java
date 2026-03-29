package mainWorkSpace;
import com.jfinal.config.*;
import com.jfinal.ext.handler.UrlSkipHandler;
import com.jfinal.template.Engine;


public class CentralContrl  extends JFinalConfig{
	public void configConstant(Constants me) {
		me.setDevMode(true);
	}
	public void configRoute(Routes me) {
		me.add("/hikvision", Login.class);

	}
	public void configEngine(Engine me) {}
	public void configPlugin(Plugins me) {}
	public void configInterceptor(Interceptors me) {}
	@Override
	public void configHandler(Handlers me) {
	    me.add(new UrlSkipHandler("^/websocket", false));	  
	}

}
