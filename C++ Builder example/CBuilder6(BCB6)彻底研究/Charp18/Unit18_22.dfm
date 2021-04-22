object Home: THome
  OldCreateOrder = False
  PageProducer = PageProducer
  AppServices = WebAppComponents
  Left = 275
  Top = 167
  Height = 440
  Width = 215
  object PageProducer: TPageProducer
    ScriptEngine = 'JScript'
    Left = 48
    Top = 8
  end
  object WebAppComponents: TWebAppComponents
    Sessions = SessionsService
    PageDispatcher = PageDispatcher
    AdapterDispatcher = AdapterDispatcher
    ApplicationAdapter = ApplicationAdapter
    EndUserAdapter = EndUserSessionAdapter
    UserListService = WebUserList
    Left = 48
    Top = 56
  end
  object ApplicationAdapter: TApplicationAdapter
    Left = 48
    Top = 104
    object TAdapterDefaultActions
    end
    object TAdapterDefaultFields
    end
  end
  object EndUserSessionAdapter: TEndUserSessionAdapter
    LoginPage = 'Login'
    Left = 48
    Top = 152
    object TAdapterDefaultActions
    end
    object TAdapterDefaultFields
    end
  end
  object PageDispatcher: TPageDispatcher
    Left = 48
    Top = 200
  end
  object AdapterDispatcher: TAdapterDispatcher
    Left = 48
    Top = 248
  end
  object SessionsService: TSessionsService
    Left = 48
    Top = 296
  end
  object WebUserList: TWebUserList
    UserItems = <
      item
        UserName = 'paul'
        Password = 'paul'
      end>
    Left = 48
    Top = 344
  end
end
