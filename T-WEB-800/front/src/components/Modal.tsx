import { useState } from 'react';
import Rodal from 'rodal';
import 'rodal/lib/rodal.css';
import '../scss/modal.scss';

interface ModalActions {
    setModalContent: (content: JSX.Element) => void;
    setOpen: (open: boolean) => void;
    setTitle: (title: JSX.Element) => void;
}

export const modalActions: ModalActions = {
    setModalContent: (_: JSX.Element) => {},
    setOpen: (_: boolean) => {},
    setTitle: (_: JSX.Element) => {},
}

export default function Modal()
{
    const [modalContent, setModalContent] = useState(<></>);
    const [open, setOpen] = useState(false);
    const [title, setTitle] = useState(<></>);

    modalActions.setModalContent = setModalContent;
    modalActions.setOpen = setOpen;
    modalActions.setTitle = setTitle;

    return (
        <Rodal visible={open} onClose={() => { setOpen(false) }} closeOnEsc className="modal" animation="zoom">
            <div className="modalContent">
                <div className="modalTitle">{title}</div>
                {modalContent}
            </div>
        </Rodal>
    )
}