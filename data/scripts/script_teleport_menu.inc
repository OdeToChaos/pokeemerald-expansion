TeleportMenu::
    lockall
    multichoicedefault 0, 0, MULTI_YESNO, 0, 1
    switch VAR_RESULT
    case 0, TP_YES
    case 1, TP_NO
    release
    end

TP_YES::
    special SetCB2WhiteOut
    waitstate
    release
    end

TP_NO::
    release
    end
